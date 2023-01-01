#include <gtest/gtest.h>
#include "chain_reaction.hpp"

typedef vector<vector<char>> game_map;
TEST(ChainSuite, AllExplodeTest) {
    game_map map1 {{'+', '+', '+', '+', '+', '+', 'x'}};
    EXPECT_EQ(true, all_explode(map1));

    game_map map2 {{'+', '+', '+', '+', '+', '0', 'x'}};
    EXPECT_EQ(false, all_explode(map2));

    game_map map3 {{{'+', '+', '0', 'x', 'x', '+', '0'},
                    {'0', '+', '+', 'x', '0', '+', 'x'}}};
    EXPECT_EQ(false, all_explode(map3));

    game_map map4 {{{'x', '0', '0'},
                    {'0', '0', '0'},
                    {'0', '0', 'x'}}};
    EXPECT_EQ(false, all_explode(map4));

    game_map map5 {{{'x', '0', 'x'},
                    {'0', 'x', '0'},
                    {'x', '0', 'x'}}};
    EXPECT_EQ(true, all_explode(map5));
}
