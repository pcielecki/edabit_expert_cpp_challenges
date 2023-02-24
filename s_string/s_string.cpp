#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using std::string;
using std::vector;

class Combinator{
public:
    Combinator(string all_chars, int wd_len) : m_indices(vector<unsigned int>(wd_len, 0)), m_all_chars(all_chars) {}
    string get() { 
        string wd;
        for(int i: m_indices) wd.push_back(m_all_chars.at(i));
        return wd;
    }
    bool next() {
        if(std::all_of(m_indices.begin(), m_indices.end(), [this](unsigned int a){return a == this->m_all_chars.size()-1;})) 
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
    vector<unsigned int> m_indices;
    const string m_all_chars;
};
    
string get_kth_string(string chars, unsigned int max_size, unsigned int k) {
    std::sort(chars.begin(), chars.end());
    vector<string> sstrings;
    for(unsigned int wd_len = 1; wd_len <= max_size; ++wd_len) {
        Combinator c(chars, wd_len);
        do {
            sstrings.push_back(c.get());
        } while (c.next());
    }
    vector<string>::iterator nth = sstrings.begin()+k-1;
    std::nth_element(sstrings.begin(), nth , sstrings.end());
    return *nth;
}
