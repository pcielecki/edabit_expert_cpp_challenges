#include <gtest/gtest.h>
#include "msg_from_space.hpp"

TEST(MessageFromSpaceSuite, MessageFromSpaceTest)
{
    EXPECT_EQ("ABCD", space_message("ABCD"));
    EXPECT_EQ("ABCDCDCD", space_message("AB[3CD]"));
    EXPECT_EQ("IFEELGOOOOOD", space_message("IF[2E]LG[5O]D"));
}

