#include <gtest/gtest.h>
#include "connect_four.hpp"

TEST(ConnectFourSuite, ConnectFourTestSingleWinColumn) {
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

TEST(ConnectFourSuite, ConnectFourTestDraw) {
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

TEST(ConnectFourSuite, ConnectFourTestSingleWinRow) {
    vector<string> moves {
        "A_Red",
        "A_Yellow",
        "B_Red",
        "B_Yellow",
        "C_Red",
        "C_Yellow",
        "D_Red",
        "A_Yellow"};
    EXPECT_EQ("Red", connect_four(moves));
}

TEST(ConnectFourSuite, ConnectFourTestSingleWinDiagonal) {
    vector<string> moves {
        "A_Red",
        "B_Yellow",
        "B_Red",
        "C_Yellow",
        "C_Red",
        "D_Yellow",
        "D_Red",
        "D_Yellow",
        "D_Red"};
    EXPECT_EQ("Red", connect_four(moves));
}

TEST(ConnectFourSuite, ConnectFourTestDoubleWinRow) {
    vector<string> moves {
        "A_Red",
        "A_Yellow",
        "B_Red",
        "B_Yellow",
        "C_Red",
        "C_Yellow",
        "D_Red",
        "D_Yellow"};
    EXPECT_EQ("Red", connect_four(moves));
}
