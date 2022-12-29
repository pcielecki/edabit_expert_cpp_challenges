#include <string>
#include <utility>
#include <algorithm>
#include <array>
#include <cctype>
#include <unordered_set>
#include "cipher.hpp"

using std::string;
using std::unordered_set;
using std::pair;

unsigned const int polybius_square_xsize = 5;
unsigned const int polybius_square_ysize = 5;
unsigned const int linear_polybius_size = polybius_square_ysize * polybius_square_ysize;


string _create_polybius_square(const string& key)
{
    string polybius_square;
    for(char c: string(key+"ABCDEFGHIKLMNOPQRSUVWXZ")) {
        if(string::npos == polybius_square.find(std::toupper(c))) {
            polybius_square += std::toupper(c);
        }
    }
    return polybius_square; 
}

static void _prepare_message(string& msg) {
    //std::remove_if(msg.begin(), msg.end(), [](unsigned char c){return !std::isalpha(c);}); // WHY ISNT IT WORKING?!
    string msg_trimmed;
    for(unsigned char c: msg) {
        if(std::isalpha(c)) {
            msg_trimmed += c;
        }
    }

    msg = msg_trimmed; 
    std::transform(msg.begin(), msg.end(), msg.begin(), [](unsigned char c){return c == 'J'? 'I' : std::toupper(c);});

    for(unsigned int idx = 0; idx < msg.length(); idx+=2) {
        if(msg[idx] == msg[idx+1])
            msg.insert(idx+1, "X");
    }
}

static unsigned int get_column_at_polybius(unsigned char c, const string& polybius) {
    return polybius.find(c) % polybius_square_ysize;
}

static unsigned int get_row_at_polybius(unsigned char c, const string& polybius) {
    return polybius.find(c) / polybius_square_ysize;
}

static const string get_polybius_by_2d_coordinates(unsigned int x, unsigned int y, const string& polybius) {
    x %= polybius_square_xsize;
    y %= polybius_square_ysize;

    return polybius.substr(x * polybius_square_xsize + y, 1);

    //rememer wrapping around
}

static string process_digraph(const string& original_digraph, const string& polybius, bool decipher) {
    unsigned int x0 = get_row_at_polybius(original_digraph[0], polybius);
    unsigned int x1 = get_row_at_polybius(original_digraph[1], polybius);

    unsigned int y0 = get_column_at_polybius(original_digraph[0], polybius);
    unsigned int y1 = get_column_at_polybius(original_digraph[1], polybius);

    string new_digraph;
    if(y0 == y1) { // same row
        unsigned int new_x0 = decipher? x0+polybius_square_xsize-1 : x0+1;
        unsigned int new_x1 = decipher? x1+polybius_square_xsize-1 : x1+1;
        new_digraph = get_polybius_by_2d_coordinates(new_x0, y0, polybius) + get_polybius_by_2d_coordinates(new_x1, y1, polybius);
    }
    else if(x0 == x1) { // same column
        unsigned int new_y0 = decipher? y0+polybius_square_ysize-1 : y0+1;
        unsigned int new_y1 = decipher? y1+polybius_square_ysize-1 : y1+1;
        new_digraph = get_polybius_by_2d_coordinates(x0, new_y0, polybius) + get_polybius_by_2d_coordinates(x1, new_y1, polybius);
    }
    else {
        new_digraph = get_polybius_by_2d_coordinates(x0, y1, polybius) + get_polybius_by_2d_coordinates(x1, y0, polybius);
    }

    return new_digraph;
}

static string _mingle(const string& msg, const string& polybius, bool decipher) {
    string encoded_msg;

    for(unsigned int idx = 0; idx < msg.length(); idx += 2) {
       encoded_msg += process_digraph(msg.substr(idx, 2), polybius, decipher);
    }
    return encoded_msg;
}

string playfair_cipher(string msg, string key, bool decipher) {
    const string polybius_square = _create_polybius_square(key);

    _prepare_message(msg);

    return _mingle(msg, polybius_square, decipher);
}
