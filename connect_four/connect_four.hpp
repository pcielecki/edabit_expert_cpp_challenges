#ifndef __connect_four__
#define __connect_four_

#include <vector>
#include <string>
using std::vector;
using std::string;

string connect_four(const vector<string>& moves);

class InvalidMoveFormatException: public std::exception {
public:
    InvalidMoveFormatException(string move) {
        msg = string("Invalid move format: ") + move + string("(should be: \"<column>_<color>\") ");
    }
    char* what() {return const_cast<char*>(msg.c_str());}
private:
    string msg;
};

#endif
