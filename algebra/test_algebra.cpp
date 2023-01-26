#include <gtest/gtest.h>
#include <string>
#include "algebra.hpp"

using std::string;

TEST(AlgebraSuite, AlgebraTest1) {
    EXPECT_EQ(17, evaluate_algebra(string("2 + x = 19")));
    EXPECT_EQ(3, evaluate_algebra(string("4 - x = 1")));
    EXPECT_EQ(24, evaluate_algebra(string("23 + 1 = x")));
}
