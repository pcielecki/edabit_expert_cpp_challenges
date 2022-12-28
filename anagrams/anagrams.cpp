#include <string>
#include <set>
#include <cctype>
#include <algorithm>

#include "anagrams.hpp"

using std::string;
using std::set;
using std::multiset;


string _strip_sentence(const string sentence) {
    string stripped_sentence = sentence;

    std::remove_if(stripped_sentence.begin(), stripped_sentence.end(), [](unsigned char c){return !std::isalpha(c);});
    std::transform(stripped_sentence.begin(), stripped_sentence.end(), stripped_sentence.begin(), [](unsigned char c){return std::tolower(c);});
    return stripped_sentence;
}

multiset<char> _strip_phrase(const string phrase) {
    multiset<char> phrase_stripped;
    for(char  c: phrase) {
        if(std::isalpha(c))
            phrase_stripped.insert(std::tolower(c));
    }
    return phrase_stripped;
}

string find_hidden_anagram(string sentence, string phrase) {
    string sentence_stripped = _strip_sentence(sentence);
    multiset<char> phrase_stripped = _strip_phrase(phrase);

    for(unsigned int frame_start_pos = 0; frame_start_pos < sentence.length() - phrase.length()+1; ++frame_start_pos) {
        multiset<char> frame;
        for(auto c: sentence_stripped.substr(frame_start_pos, phrase_stripped.size()))
            frame.insert(c);

        if(frame == phrase_stripped)
            return sentence_stripped.substr(frame_start_pos, phrase_stripped.size());
    }

    return "noutfond";
}

