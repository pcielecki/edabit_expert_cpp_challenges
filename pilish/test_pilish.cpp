#include <gtest/gtest.h>
#include "pilish.hpp"

TEST(PilishSuite, TestMatchingLenghts) {
    ASSERT_EQ("HOW I NEED A DRINK ALCOHOLIC IN NATURE AFTER THE HEAVY LECTURES INVOLVING QUANTUM MECHANICS", translate_to_pilish("HOWINEEDADRINKALCOHOLICINNATUREAFTERTHEHEAVYLECTURESINVOLVINGQUANTUMMECHANICSANDALLTHESECRETSOFTHEUNIVERSE"));
}

TEST(PilishSuite, TestSentenceShorterThanSeq) {
    ASSERT_EQ("FOR A LOOP", translate_to_pilish("FORALOOP"));
}

TEST(PilishSuite, TestWordTooShort) {
    ASSERT_EQ("CAN I MAKE A GUESS NOWWWWWWW", translate_to_pilish("CANIMAKEAGUESSNOW"));
}

TEST(PilishSuite, TestEmptyString) {
    ASSERT_EQ("", translate_to_pilish(""));
}
