#include <gtest/gtest.h>
#include <vector>
#include "ant.hpp"

using std::vector;


TEST(AntSuite, AntTest1) {
    grid initial_grid = {{1}};
    grid expected_grid = {{0, 0}};
    EXPECT_EQ(expected_grid, langtons_ant(initial_grid, 0, 0, 1, 0)); 
}

TEST(AntSuite, AntTest2) {
    grid initial_grid = {{0}};
    grid expected_grid = {{0, 1}};
    EXPECT_EQ(expected_grid, langtons_ant(initial_grid, 0, 0, 1, 0)); 
}

TEST(AntSuite, AntTest3) {
    grid initial_grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    grid expected_grid = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 1}, {0, 0, 0, 1}};
    EXPECT_EQ(expected_grid, langtons_ant(initial_grid, 2, 2, 10, 1)); 
}



