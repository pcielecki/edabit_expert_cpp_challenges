#include <gtest/gtest.h>
#include "mana.hpp"

TEST(ManaSuite, ManaTest1)
{
    EXPECT_EQ(true, can_pay_cost("WWGGR", "2WWG"));
    EXPECT_EQ(false, can_pay_cost("WWGG", "2WWG"));
    EXPECT_EQ(false, can_pay_cost("WGGGR", "2WWG"));
    EXPECT_EQ(true, can_pay_cost("WUUUBC", "UUB"));
}

TEST(ManaSuite, ManaTestOnEmptyHandReturnsFalse) {
    EXPECT_EQ(false, can_pay_cost("", "2WWG"));
}
