#include <vector>
#include <utility>
#include "ant.hpp"
using std::vector;

typedef std::pair<unsigned int, unsigned int> ant_xy;

ant_xy& make_a_step(grid& current_grid, ant_xy& xy, unsigned int direction) {
    if(!xy.second && !direction) {
        current_grid.insert(current_grid.begin(), vector<int>(current_grid.at(0).size(), 0));
        ++xy.second;
    }
    else if(xy.first == (current_grid.at(0).size()-1) && direction == 1) {
        for(vector<int>& row: current_grid)
            row.push_back(0);
    }
    else if(xy.second == (current_grid.size()-1) && direction == 2) {
        current_grid.push_back(vector<int>(current_grid.at(0).size(), 0));
    }
    else if (!xy.first && direction == 3) {
        for(vector<int>& row: current_grid) {
            row.insert(row.begin(), 0);
        }
        ++xy.first;
    }

    current_grid.at(xy.second).at(xy.first) ^= 1;
    
    switch(direction) {
        case 0:
            xy.second--;
            break;
        case 1:
            xy.first++;
            break;
        case 2:
            xy.second++;
            break;
        case 3:
            xy.first--;
    }
    return xy;
}
static int get_direction(unsigned int current_direction, ant_xy current_xy, grid& current_grid) {
    if(current_grid.at(current_xy.second).at(current_xy.first)) {
        return ++current_direction % 4;
    }
    else {
        return (current_direction+3) % 4;
    }
}

vector<vector<int>> langtons_ant(vector<vector<int>> current_grid, 
				  unsigned int initial_ant_x, 
                                  unsigned int initial_ant_y,
				  unsigned int n_iterations,
                                  unsigned int current_direction) {

    ant_xy xy = std::make_pair(initial_ant_x, initial_ant_y);

    while(n_iterations--) {
        current_direction  = get_direction(current_direction, xy, current_grid);
        xy = make_a_step(current_grid, xy, current_direction);
    }
    return current_grid;
}


