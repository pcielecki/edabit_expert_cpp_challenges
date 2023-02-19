#include <string>
#include <set>
#include <vector>
#include <cctype>
#include <algorithm>

using std::remove;
using std::set;
using std::string;
using std::vector;

bool is_pangram(string str) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string::iterator new_end = alphabet.end();
    for(char c: str)
        new_end = remove(alphabet.begin(), new_end, std::tolower(c));
    return new_end == alphabet.begin();
}

bool is_heterogram(string str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](char c){return !std::isalpha(c);}), str.end());
    std::transform(str.begin(), str.end(), str.begin(), [](char c){return std::tolower(c);});
    std::sort(str.begin(), str.end());
    return str.end() == std::adjacent_find(str.begin(), str.end());
}

bool is_tautogram(string str) {
    for(string::iterator it = str.begin(); it < str.end()-1; ++it)
        if(' ' == *it && std::tolower(*(it+1)) != std::tolower(str.at(0))) return false;
    return true;
}

bool is_transgram(string str) {
    vector<set<char>> words {set<char>()};
    for(char c: str) 
        if(' ' == c) words.push_back(set<char>());
        else words.back().insert(std::tolower(c));

    return any_of(words.at(0).begin(), words.at(0).end(), 
                  [&words](char c) {
                      return all_of(words.begin()+1, words.end(), 
                             [c](set<char> wd) 
                             {return wd.end() != find(wd.begin(), wd.end(), c);});
                  });
}

string constraint(string str) {
    if(is_pangram(str))
        return "Pangram";
    else if(is_heterogram(str))
        return "Heterogram";
    else if(is_tautogram(str))
        return "Tautogram";
    else if(is_transgram(str))
        return "Transgram";
    return "Sentence";
}
