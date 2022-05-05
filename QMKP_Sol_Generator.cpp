/*
 * MQKPSolGenerator.cpp
 *
 

#include "MQKPSolGenerator.h"
#include "MQKPInstance.h"
#include "MQKPSolution.h"

#include <time.h> //add for srand

void MQKPSolGenerator::genRandomSol(MQKPInstance &instance, MQKPSolution &solution){

	int numObjs = instance.getNumObjs();
	int numKnapsacks = instance.getNumKnapsacks();

	for (int i = 0; i < numObjs; i++){

		// srand(time(NULL)); //"true" random for rand
		int randomKnapsack = rand() % numKnapsacks;  //TODO Change to select one of the knapsacks
		solution.putObjectIn(i, randomKnapsack);
	}
}