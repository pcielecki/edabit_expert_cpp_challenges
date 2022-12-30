#include <gtest/gtest.h>
#include "rotate.hpp"

TEST(RotateTransformSuite, RotateTransform2x2_1) {
    int arr[2][2] = {{2, 4}, {0, 0}};
    int expected_rotated_arr[2][2] = {{0, 2}, {0, 4}};

    rotate_transform((int*)&arr, 2, 2, 1);
    ASSERT_EQ(expected_rotated_arr, arr);
}

TEST(RotateTransformSuite, RotateTransform2x2_2) {
    int arr[2][2] = {{2, 4}, {0, 0}};
    int expected_rotated_arr[2][2] = {{4, 0}, {2, 0}};

    rotate_transform((int*)&arr, 2, 2, -1);
    ASSERT_EQ(expected_rotated_arr, arr);
}

TEST(RotateTransformSuite, RotateTransform3x3_1) {
    int arr[3][3] = {{2, 4, 1}, {0, 0, 5}, {12, 1, 53}};
    int expected_rotated_arr[3][3] = {{1, 5, 53}, {4, 0, 1}, {2, 0, 12}};

    rotate_transform((int*)&arr, 3, 3, -1);
    ASSERT_EQ(expected_rotated_arr, arr);
}
