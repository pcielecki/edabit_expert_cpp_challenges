#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;


bool is_not_ing_wd(string wd) {
    const string wovels = "aeiouy";
    unsigned int n_sylabs = 0;

    for(char c: wd) 
        if(wovels.find(std::tolower(c)) != string::npos)
            ++n_sylabs;
    return !(1 < n_sylabs && string(wd.end()-3, wd.end()) == "ing");
}

vector<string> extract_ing_inflections(string sentence) {
    vector<string> words;
    string wd;
    for(char c: sentence) {
        if(' ' == c) {
            words.push_back(wd);
            wd = "";
        }
        else
            wd += c;
    }
    words.push_back(wd);
    vector<string>::iterator new_end = std::remove_if(words.begin(), words.end(), is_not_ing_wd);
    words.erase(new_end, words.end());
    return words;
}
