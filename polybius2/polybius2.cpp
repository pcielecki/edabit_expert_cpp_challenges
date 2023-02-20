#include <string>
#include <cctype>
#include <vector>

using std::string;
using std::vector;

const string alphabet = "abcdefghiklmnopqrstuvwxyz";

static char coordinates_to_letter2(unsigned int row, unsigned int col) {
    return alphabet.at(5 * (row-1) + col - 1); }
static unsigned int get_row_by_letter(char c) {return 1 + alphabet.find(std::tolower(c))/5;}
static unsigned int get_col_by_letter(char c) {return 1 + alphabet.find(std::tolower(c))%5;}

string cipher(const string& plaintext_orig) {
    const string chars_to_remove = " .!?,:;";
    string plaintext;
    for(char c: plaintext_orig)
        if(string::npos == chars_to_remove.find(c)) plaintext.push_back('j' == c? 'i' : c);
    
    string ciphertext2;
    vector<unsigned int> poly1_ciphertext(2 * plaintext.size(), 0);
    vector<unsigned int>::iterator it = poly1_ciphertext.begin();
    for(char c: plaintext) {
        *it = get_row_by_letter(c);
        *(it+plaintext.size()) = get_col_by_letter(c);
        std::advance(it, 1);
    }

    string ciphertext;
    for(vector<unsigned int>::const_iterator it = poly1_ciphertext.cbegin(); it < poly1_ciphertext.cend()-1; std::advance(it, 2)) 
        ciphertext.push_back(coordinates_to_letter2(*it, *(it+1)));
    return ciphertext;
}

string decipher(const string& ciphertext) {
    vector<unsigned int> poly1_cipher;
    for(char c: ciphertext) {
        poly1_cipher.push_back(get_row_by_letter(c));
        poly1_cipher.push_back(get_col_by_letter(c));
    }

    string plaintext;
    for(vector<unsigned int>::const_iterator it = poly1_cipher.cbegin(); it < poly1_cipher.cbegin()+ciphertext.size(); ++it)
        plaintext.push_back(coordinates_to_letter2(*it, *(it+ciphertext.size())));
    return plaintext;
}
