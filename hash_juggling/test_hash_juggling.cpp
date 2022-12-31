#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "hash_juggling.hpp"

using std::string;
using std::vector;




TEST(HashingSuite, HashingTest1) {
    vector<string> input_words = {"string1", "string2", "string3"};
    EXPECT_EQ("2d3b990149219819705bfe290571a9dcf5cf2a2528a2c711a57bd430ce32497f", 
              juggle_hashes(input_words));
}

TEST(HashingSuite, HashingTest2) {
    vector<string> input_words = {"quick", "brown", "fox"};
    EXPECT_EQ("7a2f7fdf31a4b14dd4f67e5ca8da3dabd7eac825eac259682e43d7e477b3d378", 
        juggle_hashes(input_words));
}

TEST(HashingSuite, HashingTest3) {
    vector<string> input_words = {"i", "am", "not", "a", "crook"};
    EXPECT_EQ("d94ffa741e59d434b9e9e2ed32c2efc128238ba29eaa79cd0283d17a04a2d93f", 
        juggle_hashes(input_words));
}


