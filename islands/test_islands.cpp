#include <gtest/gtest.h>

#include "islands.hpp"

TEST(IslandsSuite, IslandTest3x3) {

    int map1[3][3] = {{1, 0, 0}, {0 ,0, 0}, {0, 0, 1}};
    int map2[3][3] = {{1, 1, 0}, {0 ,1, 1}, {0, 0, 1}};
    int map3[3][3] = {{1, 0, 0}, {1 ,0, 0}, {1, 0, 1}};

    EXPECT_EQ(1, get_largest_island_size((int**)&map1, 3, 3));
    EXPECT_EQ(5, get_largest_island_size((int**)&map2, 3, 3));
    EXPECT_EQ(3, get_largest_island_size((int**)&map3, 3, 3));
}

TEST(IslandSuite, IslandTest5x5) {
    int map1[5][5] = {{1, 0, 0, 0, 1}, {1, 1, 1, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}};

    EXPECT_EQ(5, get_largest_island_size((int**)&map1, 5 ,5));
}

TEST(IslandSuite, IslandTest5x5WithMerging) {
    int map1[5][5] = {{1, 0, 0, 0, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 1, 0}, {1, 0, 0, 0, 0}};

    EXPECT_EQ(8, get_largest_island_size((int**)&map1, 5 ,5));
}
 // 1 0 0 0 1
//  1 1 1 0 1
//  0 0 0 1 0 - now merging
//  0 0 0 1 0  
//  1 0 0 0 0

