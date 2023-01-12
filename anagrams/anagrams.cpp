#include <string>
#include <set>
#include <cctype>
#include <algorithm>

#include "anagrams.hpp"

using std::string;
using std::set;
using std::multiset;


static string strip(const string str) {
    string stripped_sentence;
    for(char c: str)
        if(isalpha(c))
            stripped_sentence += std::tolower(c);
    return stripped_sentence;
}

string find_hidden_anagram(string sentence, string phrase) {
    string sentence_stripped = strip(sentence);
    string phrase_stripped = strip(phrase);
    string hidden_anagram = "noutfond";

    for(string::iterator it = sentence_stripped.begin(); it <= sentence_stripped.end()-phrase_stripped.size(); ++it) {
        if(std::is_permutation(it, it+phrase_stripped.size(), phrase_stripped.begin(), phrase_stripped.end())) {
            hidden_anagram = string(it, it+phrase_stripped.size());
            break;
        }
    }
    return hidden_anagram;
}

