#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using std::vector;
using std::string;

vector<string> get_dartboard_combinations(vector<unsigned int> sections, 
                                          unsigned int n_darts, 
                                          unsigned int target_score) {
    vector<unsigned int> combinations;
    for(unsigned int s: sections)
        for(unsigned int x = 0; x < n_darts; ++x)
            combinations.push_back(s);


    string permutations (n_darts, 1);
    permutations.resize(combinations.size(), 0);

    vector<vector<unsigned int>> results;
    do {
        vector<unsigned int> comb;
        for(unsigned int idx = 0; idx < combinations.size(); ++idx)
            if(permutations.at(idx)) 
                comb.push_back(combinations.at(idx));
        if((unsigned int)std::accumulate(comb.begin(), comb.end(), 0) == target_score && 
            std::none_of(results.begin(), results.end(), 
                         [comb](vector<unsigned int> ex_comb)
                         {return std::is_permutation(comb.begin(), comb.end(), ex_comb.begin(), ex_comb.end());}))
            results.push_back(comb);
    }
    while(std::prev_permutation(permutations.begin(), permutations.end()));


    vector<string> results_str;
    for(auto& r: results) {
        results_str.push_back(string());
        for(auto score: r)
            results_str.back() += std::to_string(score) + "-";
        results_str.back().erase(results_str.back().size()-1);
    }
    return results_str;

}


