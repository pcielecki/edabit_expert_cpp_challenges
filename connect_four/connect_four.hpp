#ifndef __connect_four__
#define __connect_four_

#include <vector>
#include <string>
using std::vector;
using std::string;

string connect_four(const vector<string>& moves);

class WrongColumnException : public std::exception {
public:
    WrongColumnException(string unrecognized_column_name) : msg(string("Unrecognized column: ") + unrecognized_column_name) {} 
    char* what() {return const_cast<char*>(msg.c_str());}
private:
    string msg;
};

class WrongColorException : public std::exception {
public:
    WrongColorException(string unrecognized_color) : msg(string("Unrecognized color: ") + unrecognized_color) {} 
    char* what() {return const_cast<char*>(msg.c_str());}
private:
    string msg;
};

#endif
