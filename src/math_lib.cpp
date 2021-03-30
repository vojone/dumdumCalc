/******************************************************************************
 *                            dumdumCalculator       
 *                              math_lib.cpp
 * 
 *       Purpose: Implementation of mathematical library used in calculator
 * 
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 13. 3. 2021
 *   
 * ***************************************************************************/

/**
 * @file math_lib.cpp
 * 
 * @brief Source file (implementation) of mathematical lib used in calculator
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */

#include "math_lib.h"
#include <math.h>
#include <stdexcept>

/**
 * @brief Arithmetic addition of two doubles
 * @param num1 first number to add
 * @param num2 second number to add
 * @return result of addition
 */
double add(const double num1, const double num2) {
  return num1 + num2;
}

/**
 * @brief Arithmetic subtraction of two doubles (num1 - num2)
 * @param num1 minuend
 * @param num2 subtrahend
 * @return difference of num1 and num2
 */
double sub(const double num1, const double num2) {
  return num1 - num2;
}

/**
 * @brief Arithmetic multiplication of two doubles
 * @param num1 first number to multiply
 * @param num2 second number to multiply
 * @return result of multiplication
 */
double mult(const double num1, const double num2) {
  return num1 * num2;
}

/**
 * @brief Arithmetic division of two doubles
 * @param num1 divident
 * @param num2 divisor
 * @return result of division
 */
double div(const double num1, const double num2) {
	if(num1 == 0 || num2 == 0) {
		throw std::runtime_error("Error, Not Defined");	
	}
	else {
		return num1 / num2;
	}
}

/**
 * @brief Product of all integers less or equal to num (factorial)
 * @param num number, from which is factorial made
 * @return factorial numbers from parameter
 */
long int fact(const unsigned int num) {
	if(num < 0) { // Only works up to 20, then it overflows
		throw std::runtime_error("Error, Only Positive Numbers");
	}
	
	if(num > 1){
		return num * fact(num - 1);
	}
	else if (num == 1 || num == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/**
 * @brief Exponetiation with real base and natural exponent
 * @param base (real) number which is base for exponetiation
 * @param exp natural exponent
 * @return result of exponentiation
 */
double pow(const double base, const unsigned int exp) {
	if(base < 0 || exp < 0) {
		throw std::runtime_error("Error, Only Positive Numbers");	
	}
	else {
		return pow(base, exp);
	}
}

/**
 * @brief Calculates general root of a base number 
 * @param base (real) number from which is found root
 * @param exp natural number which specifies the root
 * @return root of number in argument
 */
double root(const double base, const unsigned int exp) {
  if((base < 0 && exp % 2 == 0) || exp < 0) {
		throw std::runtime_error("Error, Only Positive Numbers");	
	}
	else {
		double exp_dbl = exp;
		
		if(base < 0 && (exp % 2) == 1){
			return -pow(-base, 1/exp_dbl);
		}
		else {
			return pow(base, 1/exp_dbl);
		}
	}
}

/**
 * @brief Calculates the absolute value of a number in argument
 * @param num number from which is calculated the absolute value
 * @return absolute value of number 
 */
double f_absol(const double num) {
	if(num < 0) {
		return -num;
	}
	else {
		return num;
	}
}

/***                          End of math_lib.cpp                          ***/
