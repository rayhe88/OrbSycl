#ifndef _RUN_COMMANDS_HPP_
#define _RUN_COMMANDS_HPP_
#include <iostream>
#include <string>

class runCommands
{
private:
    void helper(char **);
    void setNumberPoints(char **);
    void setInitialPoint(char **);
    void setOrbital(char **);
    void printSetting();

public:
    int nargc;
    int npoints;
    double r0;
    char orb;
    std::string name;
    runCommands(int, char **);
};
#endif