#include <gtest/gtest.h>
#include <string>
#include "baconian.hpp"

using std::string;


TEST(BaconianSuite, BaconianTestCipher) {
    EXPECT_EQ("MAn prEFeRS To BelIeve what he PreFERS tO Be truE.", baconify("Help me.", 
                                                                             "Man prefers to believe what he prefers to be true."));

    EXPECT_EQ("KNowlEDgE ITsElf Is power.", baconify("Help!!!", "Knowledge itself is power."));
}

TEST(BaconianSuite, BaconianTestDecipher) {
    EXPECT_EQ("help", baconify("KNowlEDgE ITsElf Is power."));
}
