/******************************************************************************
 *                            dumdumCalculator       
 *                               math_lib.h
 * 
 *       Description: Header file of mathematical library for calculator
 * 
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 12. 3. 2021
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

/*****************************ELEMENTARY FUNCTIONS****************************/

/**
 * @brief Arithmetical addition of two doubles
 * @param num1 first number to add
 * @param num2 second number to add
 * @return result of addition
 */
extern double add(double num1, double num2);

/**
 * @brief Arithmetical subtraction of two doubles (num1 - num2)
 * @param num1 minuend
 * @param num2 subtrahend
 * @return difference of num1 and num2
 */
extern double sub(double num1, double num2);

/**
 * @brief Arithmetical multiplication of two doubles
 * @param num1 first number to multiply
 * @param num2 second number to multiply
 * @return result of multiplication
 */
extern double mult(double num1, double num2);

/**
 * @brief Arithmetical division of two doubles
 * @param num1 divident
 * @param num2 divisor
 * @return result of division
 */
extern double div(double num1, double num2);

#endif //__MATH_LIB__

/***                            End of math_lib.h                          ***/
