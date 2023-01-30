#ifndef __dboard_combos__
#define __dboard_combos__

#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> get_dartboard_combinations(vector<unsigned int> sections, unsigned int n_darts, unsigned int target_score);

#endif
