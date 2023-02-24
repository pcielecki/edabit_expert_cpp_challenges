#include <gtest/gtest.h>
#include <string>
#include "s_string.hpp"

TEST(S_StringSuite, TestK2) {
    ASSERT_EQ("dd", get_kth_string("gd", 3, 2));
}
TEST(S_StringSuite, TestK10) {
    ASSERT_EQ("gdd", get_kth_string("gd", 3, 10));
}
TEST(S_StringSuite, TestK6) {
    ASSERT_EQ("ea", get_kth_string("aei", 2, 6));
}
