#include <gtest/gtest.h>
#include "polynomials.hpp"

TEST(PolynomialsSuite, TestValidScenarios) {
    EXPECT_EQ(6, evaluate_polynomial("x+1", 5));
    EXPECT_EQ(45, evaluate_polynomial("5x^2", 3));
    EXPECT_EQ(10, evaluate_polynomial("(x(x+1))/2", 4));
}

TEST(PolynomialsSuite, OnInvalidStringReturnmin1) {
    ASSERT_EQ(-1, evaluate_polynomial("4(x+3))/2",5));
}
