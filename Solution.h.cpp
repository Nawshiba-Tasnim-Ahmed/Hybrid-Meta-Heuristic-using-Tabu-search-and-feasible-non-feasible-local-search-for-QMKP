/**
 * MQKPSolution.h
 * 
 * File defining the class MQKPSolution.
 *


#ifndef __MQKPSOLUTION_H__
#define __MQKPSOLUTION_H__

#ifndef __MQKPINSTANCE_H__
#include "MQKPInstance.h"
#else
class MQKPInstance;
#endif

#include <time.h>
#include <stdlib.h>

/**
 * Class representing a solution of the problem.
 *
 * About the encoding:
 * The representation will be a vector of integer values: from 1 to M for the objects which are allocated
 * in one of the M knapsacks and 0 for those non included in any knapsack.
 */
class MQKPSolution {
  //protected:
  public:

    int * _sol;
  int _numObjs;
  double _fitness;
  /*TODO Define the properties of the class
   * _sol Integer vector, which will be the internal representation of the solution.
   * _numObjs Integer with the number of objects of the problem.
   * _fitness double value with quality of the solution.
   */

  /**
   * Constructor
   * @param[in] instance Reference to an object with the information of the MQKP instance.
   */
  MQKPSolution(MQKPInstance & instance);

  /**
   * Destructor
   */
  ~MQKPSolution();

  /**
   * Function which assigns and object to the specified knapsack
   * @param[in] object Index of the object to include in the specified knapsack
   * @param[in] knapsack Index of the knapsack where the object is going to be included
   */
  void putObjectIn(int object, int knapsack);

  /**
   * Function returning the knapsack where an object is included
   * @param[in] object Index of the object to be consulted
   * @return Index of the knapsack where the object is included
   */
  int whereIsObject(int object);
};

#endif