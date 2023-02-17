#include <gtest/gtest.h>
#include <vector>
#include "asteroids.hpp"
using std::vector;

TEST(AsteroidsSuite, NoCollisions) {
    ASSERT_EQ(vector<int>({-2, -1, 1, 2}), calculate_asteroids({-2, -1, 1, 2}));
}

TEST(AsteroidsSuite, RightmostEats1and2) {
    ASSERT_EQ(vector<int>({-2, -2}), calculate_asteroids({-2, 1, 1, -2}));
}

TEST(AsteroidsSuite, SecondEats0and1) {
    ASSERT_EQ(vector<int>({-2, -2}), calculate_asteroids({1, 1, -2, -2}));
}

TEST(AsteroidsSuite, SecondEatsFirstThenZerothEatsIt) {
    ASSERT_EQ(vector<int>({10}), calculate_asteroids({10, 2, -5}));
}

TEST(AsteroidsSuite, FullMutualAnnihilation) {
    ASSERT_EQ(vector<int>({}), calculate_asteroids({8, -8}));
}
