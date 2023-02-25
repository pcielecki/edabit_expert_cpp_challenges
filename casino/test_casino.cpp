#include <gtest/gtest.h>
#include "casino.hpp"

TEST(CasinoSuite, CasinoTestAlarm) {
    ASSERT_EQ("ALARM!",security("xxxxTTxGxx$xxTxxx")); 
}

TEST(CasinoSuite, CasinoTestSafe) {
    ASSERT_EQ("Safe", security("xxTxxG$xxxx$xxxx"));
}

TEST(CasinoSuite, CasinoTestAlarm2) {
    ASSERT_EQ("ALARM!", security("TTxxxx$xxGxx$Gxxx"));
}
