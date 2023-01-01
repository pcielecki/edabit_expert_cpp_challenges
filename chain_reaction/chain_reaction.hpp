#ifndef __chain_reaction__
#define __chain_reaction__

#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::make_pair;

bool all_explode(vector<vector<char>>& map, pair<unsigned int, unsigned int> coordinates = make_pair(0 ,0));

unsigned int how_many_to_explode_em_all(vector<vector<char>>& map);

#endif
