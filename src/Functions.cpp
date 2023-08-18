#include <cmath>
#include "Functions.hpp"

using namespace std;

#define PI 3.14159265358979323846

double Functions::orb3s(double r, double t, double p)
{
    double norm = (1. / (81. * sqrt(3. * PI)));
    double rpart = (27. - 18. * r + 2 * r * r) * exp(-r / 3.);

    return norm * rpart;
}

double Functions::orb3pz(double r, double t, double p)
{
    double norm = (sqrt(2. / PI) / 81.);
    double rpart = r * (6. - r) * exp(-r / 3.);
    double apart = cos(t);

    return norm * rpart * apart;
}

double Functions::orb3dz2(double r, double t, double p)
{
    double norm = (1. / sqrt(6. * PI) / 81.);
    double rpart = r * r * exp(-r / 3.);
    double apart = 3. * cos(t) * cos(t) - 1.;

    return norm * rpart * apart;
}

double Functions::orb2s(double r, double t, double p)
{
    double norm = (1. / 2.);
    double rpart = (1. - r / 2.) * exp(-r / 2.);
    double apart = sqrt(1. / (2. * PI));

    return norm * rpart * apart;
}

double Functions::orb2px(double r, double t, double p)
{
    double norm = (1. / 4.);
    double rpart = r * exp(-r / 2.);
    double apart = sqrt(1. / (2. * PI)) * sin(t) * cos(p);

    return norm * rpart * apart;
}

double Functions::orb2py(double r, double t, double p)
{
    double norm = (1. / 4.);
    double rpart = r * exp(-r / 2.);
    double apart = sqrt(1. / (2. * PI)) * sin(t) * sin(p);

    return norm * rpart * apart;
}

double Functions::orb2pz(double r, double t, double p)
{
    double norm = (1. / 4.);
    double rpart = r * exp(-r / 2.);
    double apart = sqrt(1. / (2. * PI)) * cos(t);

    return norm * rpart * apart;
}

double Functions::orb2sp1(double r, double t, double p)
{
    return (orb2s(r, t, p) + orb2pz(r, t, p));
}
double Functions::orb2sp2(double r, double t, double p)
{
    return (orb2s(r, t, p) + orb2px(r, t, p) + orb2py(r, t, p));
}
double Functions::orb2sp3_1(double r, double t, double p)
{
    return (0.5 * orb2s(r, t, p) + 0.5 * orb2px(r, t, p) + 0.5 * orb2py(r, t, p) + 0.5 * orb2pz(r, t, p));
}
double Functions::orb2sp3_2(double r, double t, double p)
{
    return (0.5 * orb2s(r, t, p) + 0.5 * orb2px(r, t, p) - 0.5 * orb2py(r, t, p) - 0.5 * orb2pz(r, t, p));
}
double Functions::orb2sp3_3(double r, double t, double p)
{
    return (0.5 * orb2s(r, t, p) - 0.5 * orb2px(r, t, p) + 0.5 * orb2py(r, t, p) - 0.5 * orb2pz(r, t, p));
}
double Functions::orb2sp3_4(double r, double t, double p)
{
    return (0.5 * orb2s(r, t, p) - 0.5 * orb2px(r, t, p) - 0.5 * orb2py(r, t, p) - 0.5 * orb2pz(r, t, p));
}
