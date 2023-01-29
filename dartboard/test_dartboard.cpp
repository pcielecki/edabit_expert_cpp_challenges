#include <gtest/gtest.h>
#include <vector>
#include "dartboard.hpp"

using std::vector;

TEST(DartSuite, DartTest1) {
    vector<vector<unsigned int>> expected_dartboard { {
        {1, 1, 1},
        {1, 2, 1},
        {1, 1, 1}
    }};
    ASSERT_EQ(expected_dartboard, make_dartboard(3));
}

TEST(DartSuite, DartTest2) {
    vector<vector<unsigned int>> expected_dartboard {{
        {1, 1, 1,1,1,1,1,1},
        {1,2,2,2,2,2,2,1},
        {1,2,3,3,3,3,2,1},
        {1,2,3,4,4,3,2,1},
        {1,2,3,4,4,3,2,1,},
        {1,2,3,3,3,3,2,1},
        {1,2,2,2,2,2,2,1},
        {1,1,1,1,1,1,1,1}
    }};
    ASSERT_EQ(expected_dartboard, make_dartboard(8));
}

TEST(DartSuite, DartTest3) {
    vector<vector<unsigned int>> expected_dartboard {{
    {1, 1, 1, 1, 1},
    {1, 2, 2, 2, 1},
    {1, 2, 3, 2, 1},
    {1, 2, 2, 2, 1},
    {1, 1, 1, 1, 1}
    }};
    ASSERT_EQ(expected_dartboard, make_dartboard(5));
}

