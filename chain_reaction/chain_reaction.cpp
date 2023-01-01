#include <vector>
#include <algorithm>
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

bool all_explode(vector<vector<char>>& map, pair<unsigned int, unsigned int> coordinates) {
    explode(coordinates, map);

    for(vector<char> vc: map) {
        for(char c: vc) {
            if(c != '0' && c != 'B') {
                return false;
            }
        }
    }
    return true;
}

static vector<pair<unsigned int, unsigned int>> get_positions_of_unexploded(const vector<vector<char>>& map) {
    vector<pair<unsigned int, unsigned int>> unexploded_bombs;

    for(unsigned int row_idx = 0; row_idx < map.size(); ++row_idx) {
        for(unsigned int col_idx = 0; col_idx < map.at(0).size(); ++col_idx) {
            if(map.at(row_idx).at(col_idx) == 'x' || map.at(row_idx).at(col_idx) == '+') {
                unexploded_bombs.push_back(make_pair(row_idx, col_idx));
            }
        }
    }
    return unexploded_bombs;
}

static void investigate_path(vector<vector<char>> map, unsigned int n_bombs_set_off, vector<unsigned int>& results) {
    for(pair<unsigned int, unsigned int> unexploded_bomb: get_positions_of_unexploded(map)) {
        if(all_explode(map, unexploded_bomb)) {
            results.push_back(n_bombs_set_off+1);
            return;
        }
        else {
            return investigate_path(map, n_bombs_set_off+1, results);
        }
    }
}

unsigned int how_many_to_explode_em_all(vector<vector<char>>& map) {

    vector<unsigned int> results;
    investigate_path(map, 0, results);
    return *(std::min_element(results.begin(), results.end()));
}

