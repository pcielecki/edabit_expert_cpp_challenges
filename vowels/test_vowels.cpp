#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "vowels.hpp"

using std::string;
using std::vector;

TEST(VowelsSuite, VowelsTest1) {
    vector<string> expected_results {"a", "apple", "e"};
    ASSERT_EQ(expected_results, get_vowels_substrings("apple"));
}

TEST(VowelsSuite, VowelsTestNoSubstringsReturnEmpty) {
    vector<string> expected_results {};
    ASSERT_EQ(expected_results, get_vowels_substrings("hmm"));
}

TEST(VowelsSuite, ConsonantsTest1) {
    vector<string> expected_results {"n", "t", "tion", "v", "viat", "viation"};
    ASSERT_EQ(expected_results, get_consonants_substrings("aviation"));
}

TEST(VowelsSuite, ConsonantsTest2) {
    vector<string> expected_results {"m", "mot", "motor", "r", "t", "tor"};
    ASSERT_EQ(expected_results, get_consonants_substrings("motor"));
}
