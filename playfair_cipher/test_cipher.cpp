#include <gtest/gtest.h>
#include <string>
#include "cipher.hpp"

TEST(PlayfairSuite, TestCipher1) {
    ASSERT_EQ(string("HPSYXHSHXZUGBYYBDI"), playfair_cipher(string("Tomorrow we attack."), string("python"), false));
}

TEST(PlayfairSuite, TestDecipher1) {
    ASSERT_EQ("TOMORXROWXWEATTACK", playfair_cipher("HPSYXHSHXZUGBYYBDI", "python", true));
}

TEST(PlayfairSuite, TestDecipher2) {
    ASSERT_EQ("THEXEAGLEHASLANDED", playfair_cipher("MYDZABIFBMENFEQAAE", "rhythm", true));
}
