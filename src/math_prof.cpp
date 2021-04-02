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

  while(!cin.eof()) {
    cin >> newWord;
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

int main(int argc, char *argv[]) {

  return 0;
}

/***                        End of prof_math.cpp                        ***/
