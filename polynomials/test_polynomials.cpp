#include <gtest/gtest.h>
#include "polynomials.hpp"

TEST(PolynomialsSuite, TestSimpleLevel1Scenario) {
    EXPECT_EQ(6, evaluate_polynomial("x+1", 5));
}

TEST(PolynomialsSuite, TestLevels2And3Scenarios) {
    EXPECT_EQ(45, evaluate_polynomial("5x^2", 3));
}

TEST(PolynomialsSuite, TestScenarioWithBrackets) {
    EXPECT_EQ(10, evaluate_polynomial("(x(x+1))/2", 4));
}
TEST(PolynomialsSuite, TestInvalidString) {
    ASSERT_EQ(-1, evaluate_polynomial("4(x+3))/2",5));
}
