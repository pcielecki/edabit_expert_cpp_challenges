#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using std::string;
using std::pair;
using std::vector;

using mp = pair<unsigned int, char>;

string nico_cipher(string msg, const string& key) {
    msg.insert(msg.end(), key.size() - msg.size()%key.size(), ' ');

    vector<mp> indices;
    for(unsigned int idx = 0; idx < key.size(); ++idx)
        indices.push_back(std::make_pair(idx, key.at(idx)));
    std::sort(indices.begin(), indices.end(), [](mp p1, mp p2){return p1.second < p2.second;});

    string encrypted_msg;
    while(indices.at(0).first < msg.size()) {
        for(auto& index: indices) {
            encrypted_msg.push_back(msg.at(index.first));
            index.first += key.size();
        }
    }
    return encrypted_msg;
}

