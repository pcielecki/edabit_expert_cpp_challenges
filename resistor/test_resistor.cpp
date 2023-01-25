#include <gtest/gtest.h>
#include <string>
#include "resistor.hpp"

using std::string;

TEST(ResistorSuite, ResistorTest1) {
    EXPECT_EQ(22.0, resist("(10, [20, 30])"));
    EXPECT_EQ(8.3, resist("[10, (20, 30)]"));
    EXPECT_EQ(76.7, resist("([10, 20], (30, 40))"));
    EXPECT_EQ(3.0, resist("(1, [12, 4, (1, [10, (2, 8)])])"));
    EXPECT_EQ(10.0, resist("(6, [8, (4, [8, (4, [6, (8, [6, (10, 2)])])])])"));
}
