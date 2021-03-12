/******************************************************************************
 *                            dumdumCalculator       
 *                            math_libtest.cpp
 * 
 *  Decription: TDD test for mathematical library, which is used in Calculator
 * 
 *      Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                        Last change: 12. 3. 2021
 * 
 * ***************************************************************************/

/**
 * @file math_libtest.h
 * 
 * @brief TDD test for mathematical library, which is used in calculator
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */

#include "math_lib.h"
#include "gtest/gtest.h"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

/***                        End of math_libtest.cpp                        ***/
