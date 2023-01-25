#include <gtest/gtest.h>
#include <string>
#include "algebra.hpp"

using std::string;

TEST(AlgebraSuite, AlgebraTest1) {
    EXPECT_EQ(17, "2 + x = 19");
    EXPECT_EQ(3, "4 - x = 1");
    EXPECT_EQ(24, "23 + 1 = x");
}
