#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <utility>
using std::vector;
using std::pair;
using std::set;

const vector<set<unsigned int>> dividers {
    {}, //0
    {},
    {2},
    {3},
    {2, 4},
    {5},
    {2, 3, 6},
    {7},
    {2, 4, 8},
    {3, 9},
    {2, 5, 10}
};

unsigned int get_n_proper_fractions(unsigned int max_denominator) {
    vector<unsigned int> denominators(max_denominator-1, 0);
    std::iota(denominators.begin(), denominators.end(), 2);


    unsigned int n_fractions = 0;
    for(unsigned int den: denominators) {
        for(unsigned int numerator = 1; numerator < den; ++numerator) {
            vector<unsigned int> intersect;
            std::set_intersection(dividers.at(numerator).begin(), dividers.at(numerator).end(),
                                  dividers.at(den).begin(), dividers.at(den).end(),
                                  std::back_inserter(intersect));
            if(intersect.empty()) n_fractions++;
        }
    }
    return n_fractions;
}
