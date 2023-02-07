#include <vector>
#include <string>
#include <gtest/gtest.h>
#include "ing.hpp"

using std::vector;
using std::string;

TEST(IngSuite, TestOnCorrectStringReturnWords) {
    vector<string> expected_words {"coming", "bringing", "Letting"};
    ASSERT_EQ(expected_words, extract_ing_inflections("coming bringing Letting sing"));

    expected_words = {"going", "dOing"};
    ASSERT_EQ(expected_words, extract_ing_inflections("going Ping, king sHrink dOing"));
}

TEST(IngSuite,TestOnNoInflectionsReturnEmpty) {
    ASSERT_EQ(vector<string>(), extract_ing_inflections("zing went ring, ding wing SINk"));

}


