#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

using std::string;
using std::pair;
using std::vector;
using std::isdigit;
using std::stoi;

typedef double (*t_connector)(double, float);

double connect_serial(double a, float b) {return float(a == 0? b : a*b / (a+b));}
double connect_parallel(double a, float b) {return float(a+b);}

static double calculate_subcircuit(const string& txt, string::const_iterator& it) {
    vector<double> circuit;
    t_connector connect = '[' == *it? &connect_serial : &connect_parallel;
    it = std::next(it);

    while(it != txt.end()) {
        unsigned int n_chars_to_advance = 0;
        if(isdigit(*it))
            circuit.push_back(stoi(string(it, txt.end()).c_str(), &n_chars_to_advance));
        else if(',' == *it)
            n_chars_to_advance = 2;
        else if('(' == *it || '[' == *it)
            circuit.push_back(calculate_subcircuit(txt, it));
        else {  // ] or )
            std::advance(it, 1);
            break;
        }
        std::advance(it, n_chars_to_advance);
    }
    return std::accumulate(circuit.begin(), 
                           circuit.end(), 
                           0.0,
                           connect);
}

double resist(const string& circuit_str) {
    string::const_iterator it = circuit_str.begin();
    return round(10*calculate_subcircuit(circuit_str, it)) / 10; 
}
