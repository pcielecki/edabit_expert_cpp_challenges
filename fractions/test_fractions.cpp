#include <gtest/gtest.h>
#include "fractions.hpp"

TEST(FractionsSuite, Test1) {
    EXPECT_EQ(31, get_n_proper_fractions(10));
    EXPECT_EQ(17, get_n_proper_fractions(7));
}



