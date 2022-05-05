/**
 * MQKPInstance.h
 * 
 * File defining the class MQKPInstance.
 *
 


#ifndef __MQKPINSTANCE_H__
#define __MQKPINSTANCE_H__

#ifndef __MQKPSOLUTION_H__
#include "MQKPSolution.h"
#else
class MQKPSolution;
#endif
#include<iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
/**
 * Class for storing the information of an instance of the problem MQKP
 */
class MQKPInstance {
  protected:
    int _numKnapsacks;
  int _numObjs;
  double ** _profits;
  double * _weights;
  double * _capacities;
  /*TODO Define the properties of the class:
   * _numKnapsacks Integer with number of knapsacks to consider. This is not read from the file, but established by the user.
   * _numObjs Integer with the number of objects of the problem.
   * _profits Matrix where the profits of the objects are stored. YOU HAVE TO ALLOCATE ITS MEMORY.
   * _weights Vector with the weights of the objects. YOU HAVE TO ALLOCATE ITS MEMORY.
   * _capacities Vector with the capacities of the knapsacks. YOU HAVE TO ALLOCATE ITS MEMORY. To avoid problems, store the vector
   *             for (1 + numKnapsacks) elements and use the indices from index 1
   */

  public:
    int getNumObjs();
  int getNumKnapsacks();
  /**
   * Default constructor
   */
  MQKPInstance();

  /**
   * Destructor
   */

  ~MQKPInstance();

  /**
   * Function for reading an input file.
   * @param[in] filename Name of the file where the data of the instance can be found.
   * @param[in] numKnapsacks Integer with the number of knapsacks to be considered. This is not read from the file,
   *                         but established by the user.
   */
  void readInstance(char * filename, int numKnapsacks);

  //TODO declare the methods (and define them in MQKPInstance.cpp) returning the information about the instance
  // of the problem. Among others, getNumObjs() and getNumKnapsacks()
  double getMaxCapacityViolation(MQKPSolution & solution);
  /**
   * Function returning how much the capacity constraint is is violated for the most over-weighted knapsack.
   * @param[in] solution Reference to an object representing a solution to the problem.
   * @return Maximum violation of the knapsack capacities.
   */
  /**
   * Function obtaining the sum of the individual and shared profits of the objects in the knapsacks.
   * @param[in] solution Reference to an object representing a solution to the problem.
   * @return Sum of the individual and shared profits of the objects in the knapsacks.
   */
  double getSumProfits(MQKPSolution & solution);
};

#endif