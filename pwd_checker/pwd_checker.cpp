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

static unsigned int calculate_true_n_repetitions(const string& passwd) {
    unsigned int true_n_reps = 0;
    for(unsigned int idx = 2; idx < passwd.size(); ++idx) {
        if(passwd[idx] == passwd[idx-1] && passwd[idx] == passwd[idx-2]) {
            ++true_n_reps;
            idx += 2;
        }
    }
    return true_n_reps;
}

static unsigned int calculate_n_required_changes(unsigned int passwd_size, 
                                          bool pwd_contains_lowercase, 
                                          bool pwd_contains_uppercase, 
                                          bool pwd_contains_digit,
                                          unsigned int true_n_reps) {
    unsigned int n_missing_characteristics = static_cast<unsigned int>(!pwd_contains_lowercase)
                                           + static_cast<unsigned int>(!pwd_contains_uppercase)
                                           + static_cast<unsigned int>(!pwd_contains_digit);
    unsigned int n_changes_required;

    if(passwd_size < 8) 
        n_changes_required = std::max(8 - passwd_size, std::max(true_n_reps, n_missing_characteristics)); 
        //we can add whatever we want, so we'll add every kind of char we're missing plus what's left till we've got 8
    else if(passwd_size <= 20)
        n_changes_required = std::max(n_missing_characteristics, true_n_reps);
    else 
        n_changes_required = passwd_size - 20 + std::max(n_missing_characteristics, true_n_reps); // need to remove all excessive and also swap others to what's missing
    return n_changes_required;
}

unsigned int get_n_changes_required(string passwd) {
    bool pwd_contains_digit = false;
    bool pwd_contains_uppercase = false;
    bool pwd_contains_lowercase = false;

    for(char c: passwd) {
        if(isdigit(c)) 
            pwd_contains_digit = true;
        else if(isupper(c))
            pwd_contains_uppercase = true;
        else if(islower(c))
            pwd_contains_lowercase = true;
    }
    return calculate_n_required_changes(passwd.size(),
                                        pwd_contains_lowercase,
                                        pwd_contains_uppercase,
                                        pwd_contains_digit,
                                        calculate_true_n_repetitions(passwd));
}

