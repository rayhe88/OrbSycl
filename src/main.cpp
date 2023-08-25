#include "Evaluator.hpp"
#include "runCommands.hpp"
#include "Timer.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{

    runCommands run(argc, argv);
    Timer timer;

    Evaluator evaluator(run.npoints, run.r0);
    timer.start();
    evaluator.evaluate(run.orb);
    timer.stop();

    std::cout << " Duration: " << timer.getDuration() << " us" << std::endl;
    evaluator.dumpCube(run.name);

    exit(EXIT_SUCCESS);
}
