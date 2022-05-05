/*
 * MQKPInstance.cpp
 *
 * File defining the methods of the class MQKPInstance.
 *
 * It is a part of the skeleton code provided for the MQKP, as a part of the module Metaheuristics

#include "MQKPInstance.h"
#include "MQKPSolution.h"
#include <fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
MQKPInstance::MQKPInstance() {
	//TODO complete initializing the properties
		 this->_numKnapsacks=0;
		 this->_numObjs=0;
		 this->_profits=nullptr;
		 this->_weights=nullptr;
		 this->_capacities=nullptr;

}

MQKPInstance::~MQKPInstance() {
	//TODO complete
	delete[]_weights;
	delete[]_capacities;
	for(int i=0;i<_numObjs;i++)
		delete[]_profits[i];
	delete[]_profits;
}

int MQKPInstance::getNumObjs()
{
	return this->_numObjs;
}
int MQKPInstance::getNumKnapsacks()
{
	return this->_numKnapsacks;
}
double MQKPInstance::getMaxCapacityViolation(MQKPSolution &solution) {

	double *sumWeights = new double[this->_numKnapsacks +1];

	for (int j = 1; j <= this->_numKnapsacks; j++) {
		sumWeights[j] = 0;
	}

	for (int i = 0; i < this->_numObjs; i++) {

		if(solution._sol[i] > 0)
		{
			sumWeights[solution._sol[i]]+=this->_weights[i];
		}
		/*TODO Complete
		 * 1. Obtain the knapsack where we can find the i-th object.
		 * 2. If it is a valid knapsack (higher than 0), increment sumWeights by the weight of the object.
		 */
}

double maxCapacityViolation = 0; //We initialize maximum violation to 0, meaning that there are no violations.

for (int j = 1; j <= this -> _numKnapsacks; j++) {
  if (int a = sumWeights[j] - (this -> _capacities[j]) > maxCapacityViolation) {
    maxCapacityViolation = a;
  }
  /*TODO Complete
   * 1. Obtain the violation for the j-th knapsack
   * 2. Update maxCapacityViolation if needed
   */
}

delete[] sumWeights;
return maxCapacityViolation;
}

double MQKPInstance::getSumProfits(MQKPSolution & solution) {

  double sumProfits = 0.;
  for (int i = 0; i < (this -> _numObjs - 1); i++) {
    if (solution._sol[i] >= 0) {
      sumProfits += this -> _profits[i][i];
      for (int j = i + 1; j < (this -> _numObjs); j++) {
        if (solution._sol[i] == solution._sol[j]) {
          sumProfits += this -> _profits[i][j];
        }
      }
    }
  }
  /*TODO Complete
   * Double loop for each pair of objects
   * Todo object included in any knapsack (> 0) must sum its individual profit.
   * Todo pair of objects included in the same knapsack (and with value > 0) must sum its shared profit.
   *      IMPORTANT NOTE, sum the pair (i,j) only once, that is, if you sum (i, j), you should not sum (j, i)
   */

  return sumProfits;
}

void MQKPInstance::readInstance(char * filename, int numKnapsacks) {

  using std::cout;
  using std::cin;
  using std::cerr;
  using std::endl;

  _numKnapsacks = numKnapsacks;
  std::ifstream resourse;
  resourse.open(filename);

  if (!resourse.is_open()) {
    cerr << "something goes wrong with file..." << endl;
    exit(1);
  }

  std::string data;
  getline(resourse, data); //trash - name of the file
  getline(resourse, data); //number of objs
  _numObjs = atoi(data.c_str());
  _profits = new double * [_numObjs];

  for (int i = 0; i < _numObjs; i++)
    _profits[i] = new double[_numObjs];

  for (int i = 0; i < _numObjs; i++) {
    resourse >> _profits[i][i]; //first string is diagonal

  }

  for (int i = 0; i < _numObjs - 1; i++) { //2 string of matrix, 3 string, ...
    for (int j = i + 1; j < _numObjs; j++) //has n-i-1 long
    {
      double tmp; //get a number
      resourse >> tmp;
      // std::cout << tmp << std::endl;
      _profits[i][j] = tmp; //and put it mirror from the diagonal
      _profits[j][i] = tmp;
    }
  }

  _weights = new double[_numObjs];
  getline(resourse, data); //shifting until data...
  getline(resourse, data);
  getline(resourse, data);
  getline(resourse, data); //here we are, weights
  double sum = 0;

  for (int i = 0; i < _numObjs; i++) {
    resourse >> _weights[i];
    sum += _weights[i]; //meanwhile finding the sum of weights
  }

  resourse.close(); //we've done with file
  sum *= 0.8; //capacity of all knapsacks (from the initial conditions)
  sum /= _numKnapsacks;
  _capacities = new double[_numObjs];

  for (int i = 0; i < _numObjs; i++)
    _capacities[i] = sum;

  /*
   * TODO Complete this function:
   *   1. read the number of objects
   *   2. allocate matrix and vector memory
   *   3. read profits and object weights, according to what has been previously discussed
   *   4. Obtain the capacities of the knapsacks:
   *      . Sum all the object weights
   *      . Multiply by 0.8
   *      . Divide the previous results by the number of knapsacks. This will be the capacity of each knapsack
   */
}