#include <string>
#include <cctype>
using std::string;

static const string key = "abcdefghijklmnopqrstuvwxyz6789. ";

static string cipher(const string& msg, const string& mask) {
    unsigned int in_seq_ctr = 0;
    string::const_iterator it = msg.begin();
    string encoded_msg;

    for(char c: mask) {
        if(it != msg.end() && std::isalpha(c)) {
            c = (key.find(std::tolower(*it)) & (1 << (4-in_seq_ctr))) ?
                std::tolower(c) : std::toupper(c);

            if(++in_seq_ctr == 5) {
                in_seq_ctr = 0;
                it = std::next(it);
            }
        }
        encoded_msg.push_back(c);
    }
    return encoded_msg;
};

static string decipher(const string& encoded_msg) {
    static unsigned int in_seq_ctr = 0;
    string plaintext_msg;
    unsigned int sign_idx = 0;

    for(char c: encoded_msg) {
        if(!std::isalpha(c)) continue;
        if(std::islower(c)) 
            sign_idx += (1 << (4-in_seq_ctr));
        if(++in_seq_ctr == 5) {
            plaintext_msg.push_back(key.at(sign_idx));
            in_seq_ctr = sign_idx = 0;
        }
    }
    return plaintext_msg;
}

string baconify(const string& msg, const string& mask) {
    if("" == mask) return decipher(msg);
    else return cipher(msg, mask);
} 
