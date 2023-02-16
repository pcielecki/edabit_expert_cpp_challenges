#include <string>
#include <algorithm>
#include <cctype>
#include <numeric>
using std::string;

bool can_pay_cost(string hand, string cost) {
    unsigned int total_scalar_cost = std::accumulate(cost.begin(), cost.end(), 0,
                                            [](int partial_sum, char a) 
                                            {return partial_sum + (std::isdigit(a)? std::stoi(string(1, a)) : 1);});

    const string colors = "WUBRGC";
    return total_scalar_cost <= (unsigned int)hand.size() && std::all_of(colors.begin(), colors.end(), [hand, cost](char col) {
                           return std::count(hand.begin(), hand.end(), col) >= std::count(cost.begin(), cost.end(), col);
                       }
    );
}
