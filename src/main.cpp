#include "Evaluator.hpp"
#include "runCommands.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{

    runCommands run(argc, argv);

    Evaluator evaluator(run.npoints, run.r0);

    evaluator.evaluate_sycl(run.orb);

    evaluator.dumpCube(run.name);

    exit(EXIT_SUCCESS);
}
