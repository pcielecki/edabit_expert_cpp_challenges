#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "buckets.hpp"

using std::vector;
using std::string;


TEST(BucketsSuite, BucketsTest1) {
    vector<string> expected_result{"she sells", "sea shells", "by the sea"};
    EXPECT_EQ(expected_result, bucketize("she sells sea shells by the sea", 10));
}

TEST(BucketsSuite, BucketsTest2) {
    vector<string> expected_result{"the", "mouse", "jumped", "over", "the", "cheese"};
    EXPECT_EQ(expected_result, bucketize("the mouse jumped over the cheese", 7));
}
TEST(BucketsSuite, BucketsTest3) {
    vector<string> expected_result{"fairy dust coated", "the air"};
    EXPECT_EQ(expected_result, bucketize("fairy dust coated the air", 20));
}
TEST(BucketsSuite, BucketsTest4) {
    vector<string> expected_result{"a", "b", "c", "d", "e"};
    EXPECT_EQ(expected_result, bucketize("a b c d e", 2));
}
