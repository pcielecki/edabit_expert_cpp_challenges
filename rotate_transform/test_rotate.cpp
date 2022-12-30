#include <gtest/gtest.h>
#include <vector>
#include "rotate.hpp"

using std::vector;

TEST(RotateTransformSuite, RotateTransform2x2_1) {
    vector<vector<int>> arr{{{2, 4}, {0, 0}}};
    vector<vector<int>> expected_rotated_arr{{{0, 2}, {0, 4}}};

    rotate_transform(arr, 1);
    ASSERT_EQ(expected_rotated_arr, arr);
}

TEST(RotateTransformSuite, RotateTransform2x2_neg1) {
    vector<vector<int>>arr {{{2, 4}, {0, 0}}};
    vector<vector<int>>expected_rotated_arr{{{4, 0}, {2, 0}}};

    rotate_transform(arr, -1);
    ASSERT_EQ(expected_rotated_arr, arr);
}

TEST(RotateTransformSuite, RotateTransform3x3_neg1) {
    vector<vector<int>>arr{{{2, 4, 1}, {0, 0, 5}, {12, 1, 53}}};
    vector<vector<int>>expected_rotated_arr{{{1, 5, 53}, {4, 0, 1}, {2, 0, 12}}};

    rotate_transform(arr, -1);
    ASSERT_EQ(expected_rotated_arr, arr);
}
