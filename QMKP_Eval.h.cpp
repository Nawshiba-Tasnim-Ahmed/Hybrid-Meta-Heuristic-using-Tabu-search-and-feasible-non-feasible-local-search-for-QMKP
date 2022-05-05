/**
 * MQKPEvaluator.h
 * 
 * File defining the class MQKPEvaluator.
 *


#ifndef __MQKPEvaluator_H__
#define __MQKPEvaluator_H__

#include "MQKPInstance.h"
#include "MQKPSolution.h"
#include <time.h>
#include <stdlib.h>

/**
 * Class for obtaining the fitness of a solution of the MQKP
 */
class MQKPEvaluator {

  public:
    /**
     * Function obtaining the fitness of a solution
     * @param[in] instance Reference to an object with the information of the MQKP instance.
     * @param[in] solution Reference to an object with a MQKP solution.
     * 
     * @return Solution fitness. It will be negative if the capicity constraint is violated for a
     *                           given knapsack and positive if the solution is feasible.
     *                           In this case, the value is the sum of the individual and shared profits.
     */
    static double computeFitness(MQKPInstance & instance, MQKPSolution & solution);
};

#endif