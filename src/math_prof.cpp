/******************************************************************************
 *                            dumdumCalculator       
 *                             math_prof.cpp
 * 
 *       Purpose: Implementation of mathematical library used in calculator
 * 
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 2. 4. 2021
 *   
 * ***************************************************************************/

/**
 * @file math_prof.cpp
 * 
 * @brief Source file for math library profiling
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */

#include "math_lib.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Function reads words (strings divided by blank chars) from stdin
 * @return Dynamic array of strings from stdin
 */
vector<string> readInput() {
  vector<string> strings;
  string newWord;

  while(!(cin >> newWord).eof()) { /**< Add readed string to strings until EOF*/
    strings.push_back(newWord);
  }

  return strings;
}

/**
 * @brief Converts dynamic array (vector) of strings to d. array of doubles
 * @param strings Dynamic array of strings to convert
 * @return Dynamic array of doubles
 */
vector<double> stringsToDoubles(vector<string> strings) {
  vector<double> doubles;

  for(size_t i = 0; i < strings.size(); i++) {
    doubles.push_back(stod(strings[i]));
  }

  return doubles;
}

/**
 * @brief Calculates arithmetical average of dynamic array in argument
 * @param values Dynamic array of values for calculating average
 * @return Arithmetical average of values in array
 */
double average(vector<double> values) {
  double result = 0.0;

  for(size_t i = 0; i < values.size(); i++) {
    result = add(result, values[i]);
  }

  result = div(result, values.size());

  return result;
}

/**
 * @brief Adds all squares of values from argument
 * @param values Dynamic array of values to calculate sum of their squares
 * @return Sum of squares
 */
double sumOfSquares(vector<double> values) {
  double result = 0.0;

  for(size_t i = 0; i < values.size(); i++) {
    result = add(result, f_pow(values[i], 2));
  }

  return result;
}

/**
 * @brief Calculates standard deviation from values in argument 
 * @note Uses sumOfSquares and average
 * @param values Dynamic array of values to calculate their standard deviation
 * @return Standard deviation of values in argument
 */
double stdDeviation(vector<double> values) {
  double stdDev = 0.0;
  double numberOfValues = (double)values.size();

  stdDev = f_pow(average(values), 2); /**< average^2 */
  stdDev = sub(sumOfSquares(values), mult(numberOfValues, stdDev)); /**< sumofsquares - N*(average^2) */
  stdDev = mult(div(1.0, sub(numberOfValues, 1.0)), stdDev); /**< (1/(N-1))*(sumofsquares - N*(average^2) */
  stdDev = root(stdDev, 2);

  return stdDev;
}

int main(int argc, char *argv[]) {
  vector<double> values = stringsToDoubles(readInput());

  double result = stdDeviation(values); 

  printf("%f\n", result);

  return 0;
}

/***                        End of prof_math.cpp                        ***/
