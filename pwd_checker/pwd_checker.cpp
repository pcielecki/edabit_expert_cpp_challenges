#include <string>
#include <cctype>
#include <vector>
#include <deque>

using std::string;
using std::isupper;
using std::islower;
using std::isdigit;
using std::vector;
using std::deque;

// a strong password should have
// * 8...20 characters AND
// >= 1 lowercase letter
// >= 1 uppercase letter
// >= 1 digit
// no more than 2 repeating characters in a row (aa is good, aaa is not)
unsigned int get_n_changes_required(string passwd) {
    unsigned int n_changes_required = 0;

    bool pwd_contains_digit = false;
    bool pwd_contains_uppercase = false;
    bool pwd_contains_lowercase = false;


    vector<unsigned int> repetitions;
    deque<char> last_2_chars;
    bool in_repetition = false;
    for(unsigned int idx = 0; idx < passwd.size(); ++idx) {

        char c = passwd[idx];
        if(isdigit(c)) 
            pwd_contains_digit = true;
        else if(isupper(c))
            pwd_contains_uppercase = true;
        else if(islower(c))
            pwd_contains_lowercase = true;

        if(idx >= 2 
            && last_2_chars.front() == last_2_chars.back()
            && last_2_chars.front() == c) {
            if(in_repetition)
                repetitions.back()++;
            else {
                in_repetition = true;
                repetitions.push_back(1);
            }
        }
        else
            in_repetition = false;

        if(idx >= 2)
            last_2_chars.pop_front();
        last_2_chars.push_back(c);
    }
    unsigned int n_missing_characteristics = static_cast<unsigned int>(!pwd_contains_lowercase)
                                           + static_cast<unsigned int>(!pwd_contains_uppercase)
                                           + static_cast<unsigned int>(!pwd_contains_digit);

    unsigned int true_n_reps = repetitions.size(); // TODO not really true - doesn't cover 6+ same chars in a row 
    if(passwd.size() < 8) 
        n_changes_required = std::max(8 - passwd.size(), std::max(true_n_reps, n_missing_characteristics)); 
        //we can add whatever we want, so we'll add every kind of char we're missing plus what's left till we've got 8
    else if(passwd.size() <= 20)
        n_changes_required = std::max(n_missing_characteristics, true_n_reps);
    else 
        n_changes_required = passwd.size() - 20 + std::max(n_missing_characteristics, true_n_reps); // need to remove all excessive and also swap others to what's missing
    return n_changes_required;}
