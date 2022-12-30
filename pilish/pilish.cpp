#include <string>
#include <vector>
#include "pilish.hpp"

using std::string;
using std::vector;

string translate_to_pilish2(const string &msg) {return msg; }

string translate_to_pilish(const string& msg) {
    if("" == msg)
        return "";

    const vector<int> pi_digits = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
    string pilish_msg;
    unsigned int word_begin_idx = 0;

    for(unsigned int digit: pi_digits) {
        if(word_begin_idx >= msg.size())
            break;
        else if(word_begin_idx)
            pilish_msg += " ";

        pilish_msg += msg.substr(word_begin_idx, digit);

        if(word_begin_idx + digit > msg.size()) {
            unsigned int n_missing_chars = word_begin_idx + digit - msg.size();
            while(n_missing_chars--)
                pilish_msg += msg[msg.size() - 1];
        } 
        word_begin_idx += digit;
    }
    
    return pilish_msg;
}
