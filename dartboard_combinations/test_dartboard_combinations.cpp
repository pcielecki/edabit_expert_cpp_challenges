#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "dartboard_combinations.hpp"

using std::vector;
using std::string;

TEST(DartsComboSuite, DartsTest1) {
    vector<unsigned int> sections {3, 7, 11, 14, 18};
    vector<string> expected_combos {"3-11-18", "7-7-18", "7-11-14"};
    EXPECT_EQ(expected_combos, get_dartboard_combinations(sections, 3, 32));
}

TEST(DartsComboSuite, OnNoCombinationsReturnEmpty) {
    vector<unsigned int> sections {3, 7, 11, 14, 18};
    EXPECT_EQ(vector<string>(), get_dartboard_combinations(sections, 3, 33));
}
