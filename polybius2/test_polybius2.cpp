#include <gtest/gtest.h>
#include <string>
#include "polybius2.hpp"

using std::string;

TEST(Polybius2Suite, TestCipher) {
    ASSERT_EQ("ghlcrddyaykal", cipher("I killed Mufasa!"));
}

TEST(Polybius2Suite, TestDecipher) {
    ASSERT_EQ("ikilledmufasa", decipher("ghlcrddyaykal")); 
}
