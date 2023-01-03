#include <gtest/gtest.h>
#include "connect_four.hpp"

TEST(ConnectFourSuite, ConnectFourTest1) {
    vector<string> moves {
        "A_Red",
        "B_Yellow",
        "A_Red",
        "B_Yellow",
        "A_Red",
        "B_Yellow",
        "G_Red",
        "B_Yellow"};
    EXPECT_EQ("Yellow", connect_four(moves));
}

TEST(ConnectFourSuite, ConnectFourTest2) {
    vector<string> moves {
        "A_Red",
        "B_Yellow",
        "A_Red",
        "E_Yellow",
        "F_Red",
        "G_Yellow",
        "A_Red",
        "G_Yellow"};
    EXPECT_EQ("Draw", connect_four(moves));
}
