#include <string>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;

vector<string> bucketize(string sentence, unsigned int bucket_size) {
    vector<string> buckets;
    sentence += ' ';
    unsigned int adv = 0;
    for(unsigned int idx = 0; idx < sentence.size(); idx += adv+1) {
        adv = sentence.substr(idx, bucket_size+1).rfind(' ');
        if(string::npos == adv)
            break;
        else {
            buckets.push_back(sentence.substr(idx, adv));
        }
    }
    return buckets;
}
