#include <string>
#include <iostream>
#include <vector>
#include "msg_from_space.hpp"

using std::string;
using std::vector;


string space_message(string encoded_msg) {
    string decoded_msg;
    bool inside_brackets = false;
    int my_digit;
    string my_phrase;

    for(const char c: encoded_msg) 
    {
        if('[' == c) 
        {
            inside_brackets = true;
        }
        else if(']' == c)
        {
            for(int i = 0; i < my_digit; ++i)
                decoded_msg += my_phrase;

            inside_brackets = false;
            my_digit = 0;
            my_phrase = "";
        }
        else 
        { 
            if(inside_brackets)
            {
                if(isdigit(c))
                {
                    my_digit = static_cast<int>(c) - '0';
                    std::cout << my_digit;
                }
                else 
                {
                    my_phrase += c;
                }
            }
            else 
            {
                decoded_msg += c;
            }
        }
    }
    return decoded_msg;
}
