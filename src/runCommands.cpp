#include "runCommands.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

void runCommands::setNumberPoints(char *argv[])
{
    npoints = 50;
    bool flag = false;
    for (int i = 0; i < nargc; i++)
    {
        if (argv[i][0] == '-' && argv[i][1] == 'n')
        {

            if (argv[i + 1] != NULL)
            {
                npoints = atoi(argv[i + 1]);
                flag = true;
            }
        }
    }
    if (flag == false)
        cout << " No number of points: default value is charged, 50" << endl;
}

void runCommands::setInitialPoint(char *argv[])
{
    r0 = -40.0;
    bool flag = false;
    for (int i = 0; i < nargc; i++)
    {
        if (argv[i][0] == '-' && argv[i][1] == 'd')
        {

            if (argv[i + 1] != NULL)
            {
                r0 = atof(argv[i + 1]);
                flag = true;
            }
        }
    }
    if (flag == false)
        cout << " No size of cube: default value is charged: 20 a.u." << endl;

    r0 /= 2;
    if (r0 > 0)
    {
        r0 *= -1;
    }
}

void runCommands::setOrbital(char *argv[])
{
    orb = 's';
    bool flag = false;
    for (int i = 0; i < nargc; i++)
    {
        if (argv[i][0] == '-' && argv[i][1] == 'o')
        {

            if (argv[i + 1] != NULL)
            {
                orb = (argv[i + 1][0]);
                flag = true;
            }
        }
    }
    if (flag == false)
        cout << " No orbital information: default value is charged" << endl;
    orb = tolower(orb);
    std::cout << "Orbital " << orb << std::endl;

    if (orb != 's' && orb != 'p' && orb != 'd' && orb != '1' && orb != '2' && orb != '3' && orb != '4')
        orb = 's';

    switch (orb)
    {
    case 's':
        name = "orb3s";
        break;
    case 'p':
        name = "orb3pz";
        break;
    case 'd':
        name = "orb3dz2";
        break;
    case '1':
        name = "orb2sp3_1";
        break;
    case '2':
        name = "orb2sp3_2";
        break;
    case '3':
        name = "orb2sp3_3";
        break;
    case '4':
        name = "orb2sp3_4";
        break;
    }
}

runCommands::runCommands(int argc, char *argv[])
{
    nargc = argc;
    helper(argv);

    setNumberPoints(argv);
    setInitialPoint(argv);
    setOrbital(argv);

    printSetting();
}

void runCommands::helper(char **argv)
{
    bool flag_help = false;
    for (int i = 0; i < nargc; i++)
    {
        if (argv[i][0] == '-' && (argv[i][1] == 'h' || argv[i][1] == 'H'))
            flag_help = true;
    }

    if (flag_help)
    {
        cout << "\n Usage : " << argv[0] << "[args]" << endl;
        cout << "\n"
             << endl;
        cout << "\n    -h  or -H  for showing help." << endl;
        cout << "\n    -n   [int] to set the number of points." << endl;
        cout << "\n    -d   [int] to set the distance of the cube." << endl;
        cout << "\n    -o   [char] to set the orbital (s,p,d)." << endl;

        exit(EXIT_SUCCESS);
    }
}

void runCommands::printSetting()
{
    cout << "========================================" << endl;
    cout << "           Setting parameters           " << endl;
    cout << "========================================" << endl;
    cout << " Number of points : " << npoints << endl;
    cout << " Distance of cube : " << 2. * fabs(r0) << endl;
    cout << " Orbital name     : " << name << endl;
    cout << "========================================" << endl;
}