#include "Evaluator.hpp"
#include "Functions.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>

#include <CL/sycl.hpp>

namespace sycl = cl::sycl;

Evaluator::Evaluator(int npts, double _r0)
{
    npoint = npts;
    r0 = _r0;
    step = 2. * fabs(r0) / (npoint - 1);
    nsize = npoint * npoint * npoint;
    field.resize(nsize);
}

Evaluator::~Evaluator()
{
    npoint = 0;
    r0 = 0;
    step = 0;
    nsize = 0;
    field.resize(0);
}

void Evaluator::Cart2Sphe(const double cart[3], double sphe[3])
{
    double x, y, z;
    double r;
    x = cart[0];
    y = cart[1];
    z = cart[2];

    r = sqrt(x * x + y * y + z * z);
    sphe[0] = r;
    sphe[1] = acos(z / r);
    sphe[2] = atan2(y, x);
}

functionPtr Evaluator::setFunction(char func)
{
    switch (func)
    {
    case 'p':
        return Functions::orb3pz;
    case 'd':
        return Functions::orb3dz2;
    case '1':
        return Functions::orb2sp3_1;
    case '2':
        return Functions::orb2sp3_2;
    case '3':
        return Functions::orb2sp3_3;
    case '4':
        return Functions::orb2sp3_4;
    default:
        return Functions::orb3s;
    }
}

void Evaluator::evaluate_sycl(char choice)
{

    sycl::queue q(sycl::default_selector{});

    std::cout << " Running on " << q.get_device().get_info<sycl::info::device::name>() << "\n\n";

    const size_t nsize_loc = nsize;
    double *field_local = new double[nsize_loc];
    sycl::buffer<double, 1> field_buff(field_local, sycl::range<1>(nsize_loc));

    int np = npoint;
    double r_0 = r0;
    double hstep = step;

    functionPtr function = setFunction(choice);

    q.submit([&](sycl::handler &h)
             {
                auto field_acc = field_buff.get_access<sycl::access::mode::write>(h);

                h.parallel_for<class Evaluator2>(sycl::range<1>(nsize_loc), [=](sycl::id<1> idx)
                                 {   double cart[3];
                                     double sphe[3];
                                     int k = (int)idx % np;
                                     int j = ((int)idx / np) % np;
                                     int i = (int)idx / (np * np);

                                     cart[0] = r_0 + i * hstep;
                                     cart[1] = r_0 + j * hstep;
                                     cart[2] = r_0 + k * hstep;

                                     Cart2Sphe(cart, sphe);

                                     field_acc[idx] = function(sphe[0], sphe[1], sphe[2]);
                                     }); });
    q.wait();
    for (int i = 0; i < nsize_loc; i++)
        field[i] = field_local[i];

    // delete[] field_local;
}

void Evaluator::evaluate(char choice)
{
    double cart[3];
    double sphe[3];
    functionPtr function = setFunction(choice);

    int idx = 0;
    for (int i = 0; i < npoint; i++)
    {
        cart[0] = r0 + i * step;
        for (int j = 0; j < npoint; j++)
        {
            cart[1] = r0 + j * step;
            for (int k = 0; k < npoint; k++)
            {
                cart[2] = r0 + k * step;
                Cart2Sphe(cart, sphe);
                field[idx] = function(sphe[0], sphe[1], sphe[2]);
                idx++;
            }
        }
    }
}

void Evaluator::dumpCube(std::string ninit)
{
    std::string ext(".cube");
    std::string name = ninit + ext;
    std::ofstream fout;
    fout.open(name.c_str(), std::fstream::out);

    fout << " File generated for the project" << std::endl;
    fout << " In the Gaussian cube format" << std::endl;

    fout << std::fixed;
    fout << std::setw(6) << 1 << std::setprecision(6) << std::setw(12) << r0 << std::setw(12) << r0 << std::setw(12) << r0 << std::endl;
    fout << std::setw(6) << npoint << std::setprecision(6) << std::setw(12) << step << std::setw(12) << 0.0 << std::setw(12) << 0.0 << std::endl;
    fout << std::setw(6) << npoint << std::setprecision(6) << std::setw(12) << 0.0 << std::setw(12) << step << std::setw(12) << 0.0 << std::endl;
    fout << std::setw(6) << npoint << std::setprecision(6) << std::setw(12) << 0.0 << std::setw(12) << 0.0 << std::setw(12) << step << std::endl;
    fout << std::setw(6) << 3 << std::setprecision(6) << std::setw(12) << 3.0 << std::setw(12) << 0.0 << std::setw(12) << 0.0 << std::setw(12) << 0.0 << std::endl;

    int jtmp = 0;
    fout << std::fixed;
    for (int i = 0; i < nsize; i++)
    {
        jtmp++;
        fout << std::setw(14) << std::setprecision(6) << std::scientific << field[i];
        if (i == nsize - 1 || jtmp == 6)
        {
            fout << std::endl;
            jtmp = 0;
        }
    }

    fout.close();
}
