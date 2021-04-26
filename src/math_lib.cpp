/******************************************************************************
 *                            dumdumCalculator       
 *                              math_lib.cpp
 * 
 *       Purpose: Implementation of mathematical library used in calculator
 * 
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 15. 4. 2021
 *   
 * ***************************************************************************/

/**
 * @file math_lib.cpp
 * 
 * @brief Source file (implementation) of mathematical lib used in calculator
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */

#include "math_lib.h"

#include <stdexcept>
#include <cmath>
#include <limits>

/**
 * @brief Arithmetic addition of two doubles
 * @param num1 is first term
 * @param num2 is second term
 * @return sum of num1 and num2
 */
long double add(const double num1, const double num2) {
  return num1 + num2;
}

/**
 * @brief Arithmetic subtraction of two doubles (num1 - num2)
 * @param num1 minuend
 * @param num2 subtrahend
 * @return difference of num1 and num2
 */
long double sub(const double num1, const double num2) {
  return num1 - num2;
}

/**
 * @brief Arithmetic multiplication of two doubles
 * @param num1 is multiplier
 * @param num2 is multiplicand
 * @return product of num1 and num2
 */
long double mult(const double num1, const double num2) {
  return num1 * num2;
}

/**
 * @brief Arithmetic division of two doubles
 * @param num1 is divident
 * @param num2 is divisor
 * @return fraction of num1 and num2
 */
long double div(const double num1, const double num2) {
	if(num2 == 0) {
		throw std::runtime_error("Error, Not Defined");	
	}
	
	else {
		return num1 / num2;
	}
}

/**
 * @brief Product of all integers less or equal to num (factorial)
 * @param num number, from which is factorial made
 * @return factorial of num
 */
long double fact(const double num) {
	
	if(num < 0) {
		throw std::runtime_error("Error, Only Positive Numbers");
	}
	if(fmod(num, 1) != 0.0) {
		throw std::runtime_error("Error, Only Integers");
	}
	
	//Check if the number would overflow stack or not
	if(pow(2,num) == std::numeric_limits<double>::infinity()) {
		return std::numeric_limits<double>::infinity();	
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
 * @return power of base to the exponent
 */
long double f_pow(const double base, const double exp) {
	if(exp < 0) {
		throw std::runtime_error("Error, Only Positive Numbers");
	}
  	else if(exp == 0.0 && base == 0.0) {
    	throw std::runtime_error("Error, Unspecific Expression");
  	}
  	else if(fmod(exp, 1) != 0.0) {
  		throw std::runtime_error("Error, Only Integers");
	}
  	
  	if(exp == 0) {
    	return 1.0;
  	}
	else {
		return pow(base, exp);
	}
}

/**
 * @brief Calculates general root of a radicant to the Nth degree
 * @param radicant (real) number from which root is specified
 * @param degree natural number which specifies the root
 * @return root of radicant to the degree
 */
long double root(const double radicant, const double degree) {
    if(fmod(degree, 1) != 0.0) {
		throw std::runtime_error("Error, Only Integers");
	}
    else if(degree <= 0 || (radicant < 0 && ((int)degree % 2 == 0))) {
        throw std::runtime_error("Error, Only Positive Numbers");
    }
	
	else {
		double deg_dbl = degree;
		
        if(radicant < 0 && ((int)degree % 2 == 1)){
            return -pow(-radicant, 1/deg_dbl);
		}
		else {
			return pow(radicant, 1/deg_dbl);
		}
	}
}

/**
 * @brief Calculates modulo of two numbers
 * @param num1 natural divident
 * @param num2 natural divisor
 * @return remainder of division
 */
long double modulo(const double num1, const double num2) {
	if(num2 == 0) {
		throw std::runtime_error("Error, Not Defined");
	}
	
	return std::fmod(num1, num2);
}

/***                          End of math_lib.cpp                          ***/
