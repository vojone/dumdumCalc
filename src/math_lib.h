/******************************************************************************
 *                            dumdumCalculator       
 *                               math_lib.h
 * 
 *        Purpose: Header file of mathematical library for calculator
 * 
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 15. 4. 2021
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
extern long double add(const double num1, const double num2);

/**
 * @brief Arithmetic subtraction of two doubles (num1 - num2)
 * @param num1 minuend
 * @param num2 subtrahend
 * @return difference of num1 and num2
 */
extern long double sub(const double num1, const double num2);

/**
 * @brief Arithmetic multiplication of two doubles
 * @param num1 first number to multiply
 * @param num2 second number to multiply
 * @return result of multiplication
 */
extern long double mult(const double num1, const double num2);

/**
 * @brief Arithmetic division of two doubles
 * @param num1 divident
 * @param num2 divisor
 * @return result of division
 */
extern long double div(const double num1, const double num2);

/**
 * @brief Product of all integers less or equal to num (factorial)
 * @param num number, from which is factorial made
 * @return factorial numbers from parameter
 */
extern long double fact(const double num);

/**
 * @brief Exponetiation with real base and natural exponent
 * @param base (real) number which is base for exponetiation
 * @param exp natural exponent
 * @return result of exponentiation
 */
extern long double f_pow(const double base, const double exp);

/**
 * @brief Calculates general root of a base number 
 * @param base (real) number from which is found root
 * @param exp natural number which specifies the root
 * @return root of number in argument
 */
extern long double root(const double base, const double exp);

/**
 * @brief Calculates modulo of two numbers
 * @param num1 natural divident
 * @param num2 natural divisor
 * @return remainder of division
 */
extern long double modulo(const double num1, const double num2);

#endif //__MATH_LIB__

/***                            End of math_lib.h                          ***/
