#include <cmath>
#include "Functions.hpp"

using namespace std;

#define PI 3.14159265358979323846

double Functions::orb3s(const double r, const double t, const double p)
{
    const double norm = (1. / (81. * sqrt(3. * PI)));
    const double rpart = (27. - 18. * r + 2 * r * r) * exp(-r / 3.);

    return norm * rpart;
}

double Functions::orb3pz(const double r, const double t, const double p)
{
    const double norm = (sqrt(2. / PI) / 81.);
    const double rpart = r * (6. - r) * exp(-r / 3.);
    const double apart = cos(t);

    return norm * rpart * apart;
}

double Functions::orb3dz2(const double r, const double t, const double p)
{
    const double norm = (1. / sqrt(6. * PI) / 81.);
    const double rpart = r * r * exp(-r / 3.);
    const double apart = 3. * cos(t) * cos(t) - 1.;

    return norm * rpart * apart;
}

double Functions::orb2s(const double r, const double t, const double p)
{
    const double rpart = (1. - r / 2.) * exp(-r / 2.);
    const double apart = sqrt(1. / (2. * PI));

    return 0.5 * rpart * apart;
}

double Functions::orb2px(const double r, const double t, const double p)
{
    const double rpart = r * exp(-0.5 * r);
    const double apart = sqrt(0.5 / PI) * sin(t) * cos(p);

    return 0.25 * rpart * apart;
}

double Functions::orb2py(const double r, const double t, const double p)
{
    const double rpart = r * exp(-0.5 * r);
    const double apart = sqrt(0.5 / PI) * sin(t) * sin(p);

    return 0.25 * rpart * apart;
}

double Functions::orb2pz(const double r, const double t, const double p)
{
    const double rpart = r * exp(-0.5 * r);
    const double apart = sqrt(0.5 / PI) * cos(t);

    return 0.25 * rpart * apart;
}

double Functions::orb2sp1(const double r, const double t, const double p)
{
    return (orb2s(r, t, p) + orb2pz(r, t, p));
}

double Functions::orb2sp2(const double r, const double t, const double p)
{
    return (orb2s(r, t, p) + orb2px(r, t, p) + orb2py(r, t, p));
}

double Functions::orb2sp3_1(const double r, const double t, const double p)
{
    return 0.5 * (orb2s(r, t, p) + orb2px(r, t, p) + orb2py(r, t, p) + orb2pz(r, t, p));
}

double Functions::orb2sp3_2(const double r, const double t, const double p)
{
    return 0.5 * (orb2s(r, t, p) + orb2px(r, t, p) - orb2py(r, t, p) - orb2pz(r, t, p));
}

double Functions::orb2sp3_3(const double r, const double t, const double p)
{
    return 0.5 * (orb2s(r, t, p) - orb2px(r, t, p) + orb2py(r, t, p) - orb2pz(r, t, p));
}

double Functions::orb2sp3_4(const double r, const double t, const double p)
{
    return 0.5 * (orb2s(r, t, p) - orb2px(r, t, p) - orb2py(r, t, p) + orb2pz(r, t, p));
}
