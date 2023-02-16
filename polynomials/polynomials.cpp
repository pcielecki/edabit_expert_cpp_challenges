#include <string>
#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>
#include <utility>

using std::string;
using std::vector;
using std::pair;

typedef int (*operator_function)(int, int);
const vector<vector<pair<char, operator_function>>> operators_to_operations {
    {{'+', [](int a, int b){return a+b;}}, {'-', [](int a, int b){return a-b;}}}, // level 0
    {{'*', [](int a, int b){return a * b;}}, {'/', [](int a, int b){return a / b;}}}, // level 1
    {{'^', [](int a, int b){return (int)std::pow(a, b);}}} // level 2
};

static void split_str_by_relevant_operators(string str, int level, vector<string>& operations) {
    unsigned int brackets_level = 0;
    for(char c: str) {
        if('(' == c) ++brackets_level;
        else if(')' == c) --brackets_level;
        else if(any_of(operators_to_operations.at(level).begin(), operators_to_operations.at(level).end(), 
                  [c](pair<char, operator_function> op_at_level){return c == op_at_level.first;}) && !brackets_level)
            operations.push_back(string());
        operations.back().push_back(c);
    }
}

static operator_function get_f_op_by_op(char op, int level) {
    return std::find_if(operators_to_operations.at(level).begin(), operators_to_operations.at(level).end(), 
                        [op](pair<char, operator_function> p) {
                            return p.first == op;
    })->second;
}

static int evaluate(string str, int x, unsigned int level) {
    if("x" == str) return x;
    if(std::all_of(str.begin(), str.end(), [](char c) {return (c >= '0' && c <= '9');})) return std::stoi(str);
    if('(' == str.front() && ')' == str.back()) return evaluate(string(str.begin()+1, str.end()-1), x, 0);

    vector<string> operations {""};
    split_str_by_relevant_operators(str, level, operations);

    return std::accumulate(operations.begin()+1, operations.end(), evaluate(*operations.begin(), x, level+1), 
                           [level, x](int partial_sum, string a) {
                                auto f = get_f_op_by_op(a.front(), level);
                                a.erase(a.begin());
                                return f(partial_sum, evaluate(a, x, level+1));
                           });
}
int evaluate_polynomial(string str, int x) {
    if(std::count(str.begin(), str.end(), '(') != std::count(str.begin(), str.end(), ')'))
        return -1;
    
    for(string::iterator it = str.begin(); it != str.end()-1; ++it) 
        if(((std::isdigit(*it) || 'x' == *it || ')' == *it) && '(' == *(it+1)) || (std::isdigit(*it) && 'x' == *(it+1)))
            str.insert(it+1, '*');

    return evaluate(str, x, 0);
}
