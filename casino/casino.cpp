#include <string>
#include <algorithm>
using std::string;

string security(string s) {
    s.erase(std::remove(s.begin(), s.end(), 'x'));

    const string alarming_seq1 {"T$"};
    const string alarming_seq2 {"$T"};

    if(s.end() != std::search(s.begin(), s.end(), alarming_seq1.begin(), alarming_seq1.end())
       || s.end() != std::search(s.begin(), s.end(), alarming_seq2.begin(), alarming_seq2.end()))
        return "ALARM!";
    else 
        return "Safe";
}
