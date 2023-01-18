#include <gtest/gtest.h>
#include <vector>
#include "all_subsets.hpp"

using std::vector;

TEST(AllSubsetsSuite, AllSubsetsTest1) {
    vector<vector<int>> expected_combinations {{
    {2},
    {0, 2},
    {-1, 1, 2}, 
    {-1, 0, 1, 2} }};
    EXPECT_EQ(expected_combinations, get_subsets(vector<int>({-1, 0, 1, 2}), 2));
}

TEST(AllSubsetsSuite, AllSubsetsTest2) {
    vector<vector<int>> expected_combinations {{
    {1, 2},
    {0, 1, 2}}};
    EXPECT_EQ(expected_combinations, get_subsets(vector<int>({-1, 0, 1, 2}), 3));
}

TEST(AllSubsetsSuite, AllSubsetsTest3) {
    vector<vector<int>> expected_combinations {{
    {1, 4},
    {2, 3}}};
    EXPECT_EQ(expected_combinations, get_subsets(vector<int>({1, 2, 3, 4}), 5));
}

TEST(AllSubsetsSuite, AllSubsetsTest4) {
    vector<vector<int>> expected_combinations {};
    EXPECT_EQ(expected_combinations, get_subsets(vector<int>({-1, 0, 1, 2}), 4));
}
