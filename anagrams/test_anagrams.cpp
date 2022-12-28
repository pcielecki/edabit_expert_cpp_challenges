#include <gtest/gtest.h>

#include "anagrams.hpp"

TEST(AnagramsSuite, Test_AnagramFound) {
    EXPECT_EQ("noldwestactio", find_hidden_anagram("An old west action hero actor", "Clint Eastwood"));
    EXPECT_EQ("mrmojorisin", find_hidden_anagram("Mr. Mojo Rising could be a song title", "Jim Morrison"));
    EXPECT_EQ("anamarg", find_hidden_anagram("Banana? margaritas", "ANAGRAM"));
    EXPECT_EQ("debitcard", find_hidden_anagram("D  e b90it->?$ (c)a r...d,,#~", "bad credit"));
}

TEST(AnagramsSuite, Test_AnagramsNotFound) {
    EXPECT_EQ("noutfond", find_hidden_anagram("Bright is the moon", "Bongo mirth"));
}

