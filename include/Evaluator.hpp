#ifndef _EVALUATOR_HPP
#define _EVALUATOR_HPP

#include <vector>
#include <fstream>
#include <iostream>

class Evaluator
{
private:
    int npoint;
    double r0;
    double step;
    int nsize;

    std::vector<double> field;

    static void Cart2Sphe(const double[3], double[3]);
    static double setFunction(char, const double[3]);

public:
    Evaluator(int, const double);
    ~Evaluator();
    void evaluate(char choice);
    void evaluate_sycl(char choice);
    void dumpCube(std::string name);
};

#endif
