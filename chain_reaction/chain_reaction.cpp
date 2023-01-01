#include <vector>
#include <utility>
#include "chain_reaction.hpp"

using std::vector;
using std::pair;
using std::make_pair;

void explode(pair<unsigned int, unsigned int> coordinates, vector<vector<char>>& map) {
    if(coordinates.first < 0 
       || coordinates.first > map.size()-1
       || coordinates.second < 0 
       || coordinates.second > map.at(0).size()-1)
        return;

    switch(map.at(coordinates.first).at(coordinates.second)) {
        case '0': case 'B': //B for blown up
           return;
        case '+':
            map.at(coordinates.first).at(coordinates.second) = 'B';
            explode(make_pair(coordinates.first-1, coordinates.second), map);
            explode(make_pair(coordinates.first, coordinates.second-1), map);
            explode(make_pair(coordinates.first+1, coordinates.second), map);
            explode(make_pair(coordinates.first, coordinates.second+1), map);
            break;
        case 'x':
            map.at(coordinates.first).at(coordinates.second) = 'B';
            explode(make_pair(coordinates.first-1, coordinates.second-1), map);
            explode(make_pair(coordinates.first-1, coordinates.second+1), map);
            explode(make_pair(coordinates.first+1, coordinates.second-1), map);
            explode(make_pair(coordinates.first+1, coordinates.second+1), map);
            break;
    }
}

bool all_explode(vector<vector<char>> map) {
    explode(make_pair(0, 0), map);

    for(vector<char> vc: map) {
        for(char c: vc) {
            if(c != '0' && c != 'B') {
                return false;
            }
        }
    }
    return true;
}
