#include <gtest/gtest.h>
#include "connect_four.hpp"

TEST(ConnectFourSuite, ConnectFourTestSingleWinColumn) {
    vector<string> moves {
        "A_Red",
        "B_Yellow",
        "B_Red",
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

TEST(ConnectFourSuite, DrawWhenUncontiguous4InRow) {
    vector<string> moves {
        "G_Red",
        "F_Yellow",
        "F_Red",
        "E_Yellow",
        "E_Red",
        "D_Yellow",
        "E_Red",
        "D_Yellow",
        "D_Red",
        "A_Yellow",
        "A_Red"};
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
//       R
//     R R
//   R R Y 
// R Y Y Y - Y
TEST(ConnectFourSuite, ConnectFourTestSingleWinLeftDiagonal) {
    vector<string> moves {
        "A_Red",
        "B_Yellow",
        "B_Red",
        "C_Yellow",
        "C_Red",
        "D_Yellow",
        "C_Red",
        "D_Yellow",
        "D_Red",
        "F_Yellow",
        "D_Red"};
    EXPECT_EQ("Red", connect_four(moves));
}

//       R
//       R R
//       Y R R
// Y     Y Y Y R
// =============
// A B C D E F G
//
TEST(ConnectFourSuite, ConnectFourTestSingleWinRightDiagonal) {
    vector<string> moves {
        "G_Red",
        "F_Yellow",
        "F_Red",
        "E_Yellow",
        "E_Red",
        "D_Yellow",
        "E_Red",
        "D_Yellow",
        "D_Red",
        "A_Yellow",
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
