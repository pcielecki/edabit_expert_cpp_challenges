#include <string>
#include <numeric>
#include <vector>

using std::string;
using std::accumulate;
using std::vector;

vector<int> str_to_vec(const string& eq_side) {
    vector<int> numbers;

    bool plus = true;
    for(string::const_iterator it = eq_side.begin(); it != eq_side.end();) {
        unsigned int n_chars_to_advance = 1;
        if(*it == '-') plus = false;
        else if(*it == '+') plus = true;
        else if(std::isdigit(*it)) {
            int n = std::stoi(string(it, eq_side.end()), &n_chars_to_advance);
            numbers.push_back(plus? n : -n);
        }
        std::advance(it, n_chars_to_advance);
    }
    return numbers;
}

int evaluate_algebra(string equation) {
    unsigned int eq_pos = equation.find('=');
    vector<int> left_side = str_to_vec(equation.substr(0, eq_pos-1));
    vector<int> right_side = str_to_vec(equation.substr(eq_pos+1));

    unsigned int x_pos = equation.find('x');
    bool x_on_right = (x_pos > eq_pos) ^ (x_pos > 1 && (equation.at(x_pos-2) == '-'));
    return (std::accumulate(right_side.begin(), right_side.end(), 0)
            - std::accumulate(left_side.begin(), left_side.end(), 0))
            * (x_on_right? -1 : 1);
}

