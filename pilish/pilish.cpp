#include <string>
#include <array>
#include <vector>
#include "pilish.hpp"

using std::string;
using std::vector;
using std::array;

string translate_to_pilish(const string& msg) {
    if("" == msg)
        return "";

    constexpr const array<int, 15> pi_digits = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
    string pilish_msg;
    unsigned int word_begin_idx = 0;

    for(unsigned int digit: pi_digits) {
        if(word_begin_idx >= msg.size())
            break;
        pilish_msg += msg.substr(word_begin_idx, digit) + string(" ");
        word_begin_idx += digit;
    }
    pilish_msg.pop_back(); // strip the last " "

    for(int n_missing_chars = word_begin_idx - msg.size(); n_missing_chars > 0; --n_missing_chars)
            pilish_msg += pilish_msg.back();
    return pilish_msg;
}

