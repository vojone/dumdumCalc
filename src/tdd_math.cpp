/******************************************************************************
 *                            dumdumCalculator       
 *                            math_libtest.cpp
 * 
 *  Decription: TDD test for mathematical library, which is used in Calculator
 * 
 *      Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                        Last change: 22. 4. 2021
 * 
 * ***************************************************************************/

/**
 * @file tdd_math.cpp
 * 
 * @brief TDD test for mathematical library, which is used in calculator
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */

#include "math_lib.h"
#include "gtest/gtest.h"
#include <cmath>

/**
 * @class smallPositiveDoubles set of testing values (small positive doubles)
 * @brief set of testing values for math_lib TDD tests
 */
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

/**
 * @class allDoubles set of testing values (mix of doubles)
 * @brief set of testing values for math_lib TDD tests
 */
class allDoubles : public ::testing::Test {
  protected:
    std::vector<std::vector<double>> values =
    {{0.0, -125.4}, 
    {-4294967295.1, 4294967295.0}, 
    {-789.1, -120.0},
    {123456789.123456789, -123456789.987654321}, 
    {-9223372036854775807.75, -123456.5}, 
    {123456789.0, 1.0}, 
    {4294967295.1, 4294967295.0}, 
    {4294967295.0, -4294967295.1},
    {123456789.123456789, 123456789.987654321}, 
    {9223372036854775807.75, 123456.5}};
};

/***                             ADD TESTS                                 ***/
TEST_F(smallPositiveDoubles, addition) {
  for(size_t i = 0; i < values.size(); i++) {
    double num1 = values[i][0], num2 = values[i][1];
    ASSERT_DOUBLE_EQ(num1 + num2, add(num1, num2));
  }
}

TEST_F(allDoubles, addition) {
  for(size_t i = 0; i < values.size(); i++) {
    double num1 = values[i][0], num2 = values[i][1];
    ASSERT_DOUBLE_EQ(num1 + num2, add(num1, num2));
  }
}


/***                             SUB TESTS                                 ***/
TEST_F(smallPositiveDoubles, subtraction) {
  for(size_t i = 0; i < values.size(); i++) {
    double num1 = values[i][0], num2 = values[i][1];
    ASSERT_DOUBLE_EQ(num1 - num2, sub(num1, num2));
  }
}

TEST_F(allDoubles, subtraction) {
  for(size_t i = 0; i < values.size(); i++) {
    double num1 = values[i][0], num2 = values[i][1];
    ASSERT_DOUBLE_EQ(num1 - num2, sub(num1, num2));
  }
}



/***                            MULT TESTS                                 ***/
TEST_F(smallPositiveDoubles, multiplication) {
  for(size_t i = 0; i < values.size(); i++) {
    double num1 = values[i][0], num2 = values[i][1];
    ASSERT_DOUBLE_EQ(num1 * num2, mult(num1, num2));
  }
}

TEST_F(allDoubles, multiplication) {
  for(size_t i = 0; i < values.size(); i++) {
    double num1 = values[i][0], num2 = values[i][1];
    ASSERT_DOUBLE_EQ(num1 * num2, mult(num1, num2));
  }
}



/***                            DIV TESTS                                 ***/
TEST_F(smallPositiveDoubles, division) {
  for(size_t i = 0; i < values.size(); i++) {
    double num1 = values[i][0], num2 = values[i][1];
    ASSERT_DOUBLE_EQ(num1/num2, div(num1, num2));
  }
}

TEST_F(allDoubles, division) {
  for(size_t i = 0; i < values.size(); i++) {
    double num1 = values[i][0], num2 = values[i][1];
    ASSERT_DOUBLE_EQ(num1/num2, div(num1, num2));
  }
}

TEST(errHandling, division) {
  ASSERT_ANY_THROW(div(1.0, 0.0));
  ASSERT_ANY_THROW(div(0.0, 0.0));
  ASSERT_ANY_THROW(div(100.0, 0.0));
}

/***                         MODULO TESTS                                ***/



/***                            FACT TESTS                                 ***/
TEST(factorialTests, smallPositiveIntegers) {
  std::vector<std::vector<long long unsigned int>> values = {
    {0, 1},
    {1, 1},
    {3, 6},
    {10, 3628800},
    {20, 2432902008176640000},
  };

  for(size_t i = 0; i < values.size(); i++) {
    ASSERT_EQ(fact(values[i][0]), values[i][1]);
  }
}

TEST(errHandling, fact) {
  ASSERT_ANY_THROW(fact(-10));
  ASSERT_ANY_THROW(fact(-50));
  ASSERT_ANY_THROW(fact(4.2));

  ASSERT_TRUE(std::isinf(fact(1200)));
}

/*** Checks if lib prevents overflow at huge numbers (because of recursion)***/
TEST(errHandling, factStackOver) {
  ASSERT_TRUE(std::isinf(fact(99999999)));
  ASSERT_TRUE(std::isinf(fact(123456789)));
}

/***                             POW TESTS                                 ***/
TEST(smallPositiveDoublesPow, f_pow) {
  std::vector<std::vector<double>> values = {
    {0.0, 1, 0.0},
    {1.0, 0, 1.0},
    {2.0, 2, 4.0},
    {-3.0, 4, 81.0},
    {3.0, 7, 2187.0},
    {2.2, 3, 10.648},
    {1.2, 2, 1.44}
  };

  for(size_t i = 0; i < values.size(); i++) {
    ASSERT_DOUBLE_EQ(f_pow(values[i][0], (int)values[i][1]), values[i][2]);
  }
}

TEST(errHandling, f_pow) {
  ASSERT_ANY_THROW(f_pow(0.0, 0));
  ASSERT_ANY_THROW(f_pow(-7, -8));
  ASSERT_ANY_THROW(f_pow(2, 2.1));

  ASSERT_TRUE(std::isinf(f_pow(123456789.0, 100)));
}



/***                             ROOT TESTS                                 ***/
TEST(smallPositiveDoublesRoot, root) {
  std::vector<std::vector<double>> values = {
    {0.0, 1, 0.0},
    {9, 1, 9.0},
    {4.0, 2, 2.0},
    {256, 4, 4.0},
    {27.0, 3, 3.0},
    {100000, 5, 10.0},
    {1.21, 2, 1.1}
  };

  for(size_t i = 0; i < values.size(); i++) {
    ASSERT_DOUBLE_EQ(root(values[i][0], (int)values[i][1]), values[i][2]);
  }
}

TEST(negativeDoublesRoot, root) {
  std::vector<std::vector<double>> values = {
    {-9, 1, -9.0},
    {-1000, 3, -10},
    {-243, 5, -3},
    {-128, 7, -2}
  };

  for(size_t i = 0; i < values.size(); i++) {
    ASSERT_DOUBLE_EQ(root(values[i][0], (int)values[i][1]), values[i][2]);
  }
}

TEST(errHandling, root) {
  ASSERT_ANY_THROW(root(0.0, 0));
  ASSERT_ANY_THROW(root(-7, -8));
  ASSERT_ANY_THROW(root(0.0, -7));
  
  ASSERT_NO_THROW(root(-4,3));
  ASSERT_ANY_THROW(root(-4,2));

  ASSERT_ANY_THROW(root(4,4.2));
}

/***                            MOD TESTS                                  ***/

TEST(moduloTests, smallIntegers) {
  std::vector<std::vector<int>> values = {
    {15, 4},
    {17, 3},
    {100001, 10},
    {-7, 3},
    {-8, -9}
  };

  for(size_t i = 0; i < values.size(); i++) {
    ASSERT_EQ(modulo(values[i][0],values[i][1]), values[i][0] % values[i][1]);
  }
}

TEST(errHandling, modulo) {
  ASSERT_ANY_THROW(modulo(0.0, 0));
  ASSERT_ANY_THROW(modulo(4.0, 0));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

/***                        End of math_libtest.cpp                        ***/
