#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using std::string;
using std::pair;
using std::vector;

string nico_cipher(const string& msg, const string& key) {
    vector<pair<char, string>> ciphering_matrix;
    for(char c: key)
        ciphering_matrix.push_back(std::make_pair(c, string()));

    unsigned int column_idx = 0;
    for(char c: msg) {
        ciphering_matrix.at(column_idx++).second.push_back(c);
        if(column_idx >= key.size())
            column_idx = 0;
    }
    for(auto& col: ciphering_matrix)
        while(col.second.size() < ciphering_matrix.at(0).second.size())
            col.second.push_back(' ');

    std::sort(ciphering_matrix.begin(), 
              ciphering_matrix.end(), 
              [](pair<int, string> p1, pair<int, string> p2) {
                  return p1.first < p2.first; });

    string encrypted_msg;
    for(unsigned int row_idx = 0; row_idx < ciphering_matrix.at(0).second.size(); ++row_idx)
        for(auto& col: ciphering_matrix)
            encrypted_msg.push_back(col.second.at(row_idx));

    return encrypted_msg;
}
