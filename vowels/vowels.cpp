#include <string>
#include <algorithm>
#include <vector>
#include "vowels.hpp"

using std::string;
using std::vector;

const string vowels = "aeiouy";

void get_subs(const string& s, vector<string>& subs, bool consonants) {
    vector<unsigned int> vowels_indices;
    for(unsigned int i = 0; i < s.size(); ++i)
        if((string::npos == vowels.find(s.at(i))) == consonants) 
            vowels_indices.push_back(i);

    for(unsigned int i = 0; i < vowels_indices.size(); ++i) {
        for(unsigned int j = i; j < vowels_indices.size(); ++j) {
            subs.push_back(s.substr(vowels_indices.at(i), vowels_indices.at(j)-vowels_indices.at(i)+1));
        }
    }
    std::sort(subs.begin(), subs.end());
}
vector<string> get_vowels_substrings(const string& s) {
    vector<string> subs;
    get_subs(s, subs, false);
    return subs;
}

vector<string> get_consonants_substrings(const string& s) {
    vector<string> subs;
    get_subs(s, subs, true);
    return subs;   
}


