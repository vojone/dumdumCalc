/******************************************************************************
 *                            dumdumCalculator       
 *                            math_libtest.cpp
 * 
 *  Decription: TDD test for mathematical library, which is used in Calculator
 * 
 *      Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                        Last change: 19. 3. 2021
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

/**
 * A set of testing values (small positive doubles) 
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
 * A set of testing values (mix of doubles) 
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



/***                            FABS TESTS                                 ***/
TEST_F(allDoubles, absVal) {
  for(size_t i = 0; i < values.size(); i++) {
    for(size_t u = 0; u < values[i].size(); u++) {
      double num = values[i][u];
      ASSERT_DOUBLE_EQ(fabs(num), num < 0 ? -num : num);
    }
  }
}

/***                            FACT TESTS                                 ***/
TEST(factorialTests, smallPositiveIntegers) {
  std::vector<std::vector<long long int>> values = {
    {0, 1},
    {1, 1},
    {3, 6},
    {10, 3628800},
    {25, 6227020800},
  };

  for(size_t i = 0; i < values.size(); i++) {
    ASSERT_EQ(fact(values[i][0]), values[i][1]);
  }
}

TEST(errHandling, fact) {
  ASSERT_ANY_THROW(fact(-10));
  ASSERT_ANY_THROW(fact(-50));

  ASSERT_ANY_THROW(fact(1000));
}



/***                             POW TESTS                                 ***/
TEST(smallPositiveDoublesPow, pow) {
  std::vector<std::vector<double>> values = {
    {0.0, 1, 0.0},
    {1.0, 0, 0.0},
    {2.0, 2, 4.0},
    {-3.0, 4, -81.0},
    {8.5, 7, 3205770.883},
  };

  for(size_t i = 0; i < values.size(); i++) {
    ASSERT_EQ(pow(values[i][0], (int)values[i][1]), values[i][2]);
  }
}

TEST(errHandling, pow) {
  ASSERT_ANY_THROW(pow(0.0, 0));
  ASSERT_ANY_THROW(pow(-7, -8));

  ASSERT_ANY_THROW(pow(123456789.0, 100));
}



/***                             ROOT TESTS                                 ***/
TEST(smallPositiveDoublesRoot, root) {
  std::vector<std::vector<double>> values = {
    {0.0, 1, 0.0},
    {9, 1, 0.0},
    {2.0, 2, 1.0},
    {256, 4, 4.0},
    {27.0, 3, 3.0},
  };

  for(size_t i = 0; i < values.size(); i++) {
    ASSERT_EQ(root(values[i][0], (int)values[i][1]), values[i][2]);
  }
}

TEST(errHandling, root) {
  ASSERT_ANY_THROW(pow(0.0, 0));
  ASSERT_ANY_THROW(pow(-7, -8));
  ASSERT_ANY_THROW(pow(0.0, -7));
}




int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

/***                        End of math_libtest.cpp                        ***/
