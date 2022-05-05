/**
 * MQKPSolGenerator.h
 * 


#ifndef __MQKPSOLGENERATOR_H__
#define __MQKPSOLGENERATOR_H__

#include "MQKPInstance.h"
#include "MQKPSolution.h"
#include <time.h>
#include <stdlib.h>

/**
 * Class for generating a random solution of the MQKP
 *
 * About the representation of the solutions:
 * The representation will be a vector of integer values: from 1 to M for the objects which are allocated
 * in one of the M knapsacks and 0 for those non included in any knapsack.
 */
class MQKPSolGenerator {

  public:

    /**
     * Function which generates a random solution for the MQKP
     * @param[in] instance Reference to an object with the information of the MQKP instance.
     * @param[out] solution Reference to an object representing a solution to the problem.
     *             IMPORTANT NOTE: it has to be correctly initialize. Specifically, its internal
     *             vector has to be previously reserved.
     */
    static void genRandomSol(MQKPInstance & instance, MQKPSolution & solution);
};

#endif