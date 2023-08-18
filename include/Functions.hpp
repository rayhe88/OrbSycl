#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <CL/sycl.hpp>

class Functions
{
public:
    static SYCL_EXTERNAL double orb3s(double, double, double);
    static SYCL_EXTERNAL double orb3pz(double, double, double);
    static SYCL_EXTERNAL double orb3dz2(double, double, double);
    static SYCL_EXTERNAL double orb2s(double, double, double);
    static SYCL_EXTERNAL double orb2px(double, double, double);
    static SYCL_EXTERNAL double orb2py(double, double, double);
    static SYCL_EXTERNAL double orb2pz(double, double, double);
    static SYCL_EXTERNAL double orb2sp1(double, double, double);
    static SYCL_EXTERNAL double orb2sp2(double, double, double);
    static SYCL_EXTERNAL double orb2sp3_1(double, double, double);
    static SYCL_EXTERNAL double orb2sp3_2(double, double, double);
    static SYCL_EXTERNAL double orb2sp3_3(double, double, double);
    static SYCL_EXTERNAL double orb2sp3_4(double, double, double);
};
#endif // FUNCTIONS_HPP
