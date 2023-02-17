#include <gtest/gtest.h>
#include "writing.hpp"


TEST(ConstrainedWritingSuite, TestPangram) {
    ASSERT_EQ("Pangram", constraint("The quick brown fox jumps over the lazy dog"));
}

TEST(ConstrainedWritingSuite, TestHeterogram) {
    ASSERT_EQ("Heterogram", constraint("The big dwarf only jumps"));
}

TEST(ConstrainedWritingSuite, TestTautogram) {
    ASSERT_EQ("Tautogram", constraint("Todd told Tom to take the tiny turtles."));
}

TEST(ConstrainedWritingSuite, TestTransgram) {
    ASSERT_EQ("Transgram", constraint("A cannibal alligator has attacked an unaware vegan aligator"));
}

TEST(ConstrainedWritingSuite, TestSentence) {
    ASSERT_EQ("Sentence", constraint("The unbearable lightness of coding..."));
}
