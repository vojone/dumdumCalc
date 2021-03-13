/******************************************************************************
 *                            dumdumCalculator       
 *                            math_libtest.cpp
 * 
 *  Decription: TDD test for mathematical library, which is used in Calculator
 * 
 *      Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                        Last change: 13. 3. 2021
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

class smallPositiveDoubles : public ::testing::Test {
  protected:
    std::vector<std::vector<double>> values = 
    {{1.0, 1.0}, 
    {2.5, 2.5}, 
    {3.0, 1.0}, 
    {4.0, 4.0},
    {4.333, 4.333},
    {1.0, 3.0},
    {0.0, 0.123456789123456789},
    {0.0000000000001, 0.1},
    {50.0, 50.000004},
    {123.75, 123.75}};
};

class greatPositiveDoubles : public ::testing::Test {
  protected:
    std::vector<std::vector<double>> values = 
    {{123456789.0, 1.0}, 
    {4294967295.1, 4294967295.0}, 
    {4294967295.0, 4294967295.1},
    {123456789.123456789, 123456789.987654321}, 
    {9223372036854775807.75, 123456.5}};
};

class allDoubles : public ::testing::Test {
  protected:
    std::vector<std::vector<double>> values = 
    {{-100.0, -125.4}, 
    {-4294967295.1, 4294967295.0}, 
    {-789.1, -120.0},
    {123456789.123456789, -123456789.987654321}, 
    {-9223372036854775807.75, -123456.5}};
};

class integers : public ::testing::Test {
  protected:
    std::vector<std::vector<long long int>> values = 
    {{1, 4}, 
    {123456789, 4567}, 
    {123456789, 0}, 
    {-8, 2},
    {789, -1},
    {-5, 6},
    {-3, -7},
    {8, 4294967295},
    {123456789, 123456789},
    {9223372036854775807, 1}};
};

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

/***                        End of math_libtest.cpp                        ***/
