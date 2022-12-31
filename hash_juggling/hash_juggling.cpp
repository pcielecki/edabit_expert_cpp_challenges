#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>
#include <openssl/sha.h>
#include "hash_juggling.hpp"

using std::vector;
using std::string;

static void calculate_h256(string input_str, unsigned char* output_buf) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input_str.c_str(), input_str.size());
    SHA256_Final(output_buf, &sha256);
}

static string uchar_to_hex_str(unsigned char ch) {
    const char hex_signs[16] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    return string(1, hex_signs[ch / 16]) + string(1, hex_signs[ch % 16]);
}

string sort_hash(unsigned char* hash) {
    string letters;
    string digits;

    for(unsigned int idx = 0; idx < SHA256_DIGEST_LENGTH; ++idx) {
        string octate = uchar_to_hex_str(hash[idx]);
        for(char ch: octate) {
            if(std::isalpha(ch))
                letters += ch;
            else 
                digits += ch; 
        }
    }
    return letters + digits;
}

string juggle_hashes(vector<string> &words) {
   string merged_words;
    for(string word: words)
        merged_words += word;

    unsigned char hash_buf[SHA256_DIGEST_LENGTH];
    calculate_h256(merged_words, hash_buf);

    string sorted_hash = sort_hash(hash_buf);

    calculate_h256(sorted_hash, hash_buf);

    string hashed_hash;
    for(unsigned char c: hash_buf)
        hashed_hash += uchar_to_hex_str(c);
    return hashed_hash;
}
