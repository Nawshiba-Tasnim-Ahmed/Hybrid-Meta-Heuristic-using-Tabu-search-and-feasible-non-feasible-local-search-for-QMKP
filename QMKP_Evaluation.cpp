/*
 * MQKPEvaluator.cpp
 *
 * File defining the methods of the class MQKPEvaluator.*

#include "MQKPSolution.h"
#include "MQKPInstance.h"
#include "MQKPEvaluator.h"

double MQKPEvaluator::computeFitness(MQKPInstance &instance, MQKPSolution &solution){

	double fitness = 0;
	double maxViolation= instance.getMaxCapacityViolation(solution);
	if(maxViolation>0)
	{ fitness= maxViolation*(-1);}
	/*
	 * TODO Calculate the fitness of the solution in the following way:
	 *   1. Obtain the maximum violation of the knapsack capacities, by using the corresponding function.
	 *   2. If it is higher than 0, then return the maximum violation multiplied by -1.
	 *   3. If not, the return the sum of the individual and share profits using the corresponding function.
	 */
else {
  fitness = instance.getSumProfits(solution);
}
return fitness;
}