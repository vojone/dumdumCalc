/******************************************************************************
 *                            dumdumCalculator       
 *                               math_lib.h
 * 
 *        Purpose: Header file of mathematical library for calculator
 * 
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 13. 3. 2021
 *   
 * ***************************************************************************/

/**
 * @file math_lib.h
 * 
 * @brief Header file for mathematical library used in calculator
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */

#ifndef __MATH_LIB__
#define __MATH_LIB__

/**
 * @brief Arithmetic addition of two doubles
 * @param num1 first number to add
 * @param num2 second number to add
 * @return result of addition
 */
extern double add(const double num1, const double num2);

/**
 * @brief Arithmetic subtraction of two doubles (num1 - num2)
 * @param num1 minuend
 * @param num2 subtrahend
 * @return difference of num1 and num2
 */
extern double sub(const double num1, const double num2);

/**
 * @brief Arithmetic multiplication of two doubles
 * @param num1 first number to multiply
 * @param num2 second number to multiply
 * @return result of multiplication
 */
extern double mult(const double num1, const double num2);

/**
 * @brief Arithmetic division of two doubles
 * @param num1 divident
 * @param num2 divisor
 * @return result of division
 */
extern double div(const double num1, const double num2);

/**
 * @brief Product of all integers less or equal to num (factorial)
 * @param num number, from which is factorial made
 * @return factorial numbers from parameter
 */
extern long int fact(const unsigned int num);

/**
 * @brief Exponetiation with real base and natural exponent
 * @param base (real) number which is base for exponetiation
 * @param exp natural exponent
 * @return result of exponentiation
 */
extern double pow(const double base, const unsigned int exp);

/**
 * @brief Calculates general root of a base number 
 * @param base (real) number from which is found root
 * @param exp natural number which specifies the root
 * @return root of number in argument
 */
extern double root(const double base, const unsigned int exp);

/**
 * @brief Calculates the absolute value of a number in argument
 * @param num number from which is calculated the absolute value
 * @return absolute value of number 
 */
extern double fabs(const double num);

#endif //__MATH_LIB__

/***                            End of math_lib.h                          ***/
