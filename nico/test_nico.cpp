#include <gtest/gtest.h>
#include <string>
#include "nico.hpp"

using std::string;

TEST(NicoSuite, NicoTest1) {
    ASSERT_EQ("bmusarhiahass n", nico_cipher("mubashirhassan", "crazy"));
}

TEST(NicoSuite, NicoTest2) {
    ASSERT_EQ("deabtiismaaznig ", nico_cipher("edabitisamazing", "matt"));
}

TEST(NicoSuite, NicoTest3) {
    ASSERT_EQ("lovehir    e", nico_cipher("iloveher", "612345"));
}
