#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
using std::vector;
using std::string;

static vector<vector<int>> comb(vector<int> numbers, unsigned int k) {
    vector<vector<int>> combinations;
    string bitmask(k, 1);
    bitmask.resize(numbers.size(), 0);

    do {
        combinations.push_back(vector<int>());
        for(unsigned idx = 0; idx < numbers.size(); ++idx)
            if(bitmask[idx])
                combinations.back().push_back(numbers.at(idx));
    }
    while(std::prev_permutation(bitmask.begin(), bitmask.end()));
    return combinations;
}

vector<vector<int>> get_subsets(vector<int> numbers, int requested_result) {

    vector<vector<int>> results;
    for(unsigned int combination_len = 1; combination_len <= numbers.size(); ++combination_len) {
        for(vector<int> combination: comb(numbers, combination_len))
            if(requested_result == std::accumulate(combination.begin(), combination.end(), 0))
                results.push_back(combination);
    }
    return results;
}

