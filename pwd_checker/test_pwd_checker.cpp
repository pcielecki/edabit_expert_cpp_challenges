#include <gtest/gtest.h>
#include "pwd_checker.hpp"

TEST(PwdCheckerSuite, PwdCheckerTest1) {
    EXPECT_EQ(1, get_n_changes_required("Edabit!"));
    EXPECT_EQ(1, get_n_changes_required("edabit1!"));
    EXPECT_EQ(3, get_n_changes_required("EDABITEDABITEDABITEDA"));
    EXPECT_EQ(1, get_n_changes_required("Edaaaabit!!1"));
}
