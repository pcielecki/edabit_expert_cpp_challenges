#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using std::string;
using std::vector;

class Combinator{
public:
    Combinator(string all_chars, int wd_len) : m_all_chars(all_chars), m_indices(vector<int>(wd_len, 0)) {}
    string get() { 
        string wd;
        for(int i: m_indices) wd.push_back(m_all_chars.at(i));
        return wd;
    }
    bool next() {
        if(std::all_of(m_indices.begin(), m_indices.end(), [this](int a){return a == this->m_all_chars.size()-1;})) 
            return false;
        else {
            ++m_indices.at(0);
            for(auto it = m_indices.begin(); it < m_indices.end(); ++it) {
                if(*it >= m_all_chars.size()) {
                    *(it+1) += 1;
                    *it = 0;
                }
                else
                    break;
            }
        }
        return true;
    }
private:
    vector<int> m_indices;
    const string m_all_chars;
};
    
string get_kth_string(string chars, unsigned int max_size, unsigned int k) {
    std::sort(chars.begin(), chars.end());
    vector<string> sstrings;
    for(int wd_len = 1; wd_len <= max_size; ++wd_len) {
        Combinator c(chars, wd_len);
        do {
            sstrings.push_back(c.get());
        } while (c.next());
    }
    std::sort(sstrings.begin(), sstrings.end());
    return sstrings.at(k-1);
}
