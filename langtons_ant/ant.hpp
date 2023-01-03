#ifndef __langtons_ant__
#define __langtons_ant__

#include <vector>
using std::vector;

vector<vector<int>> langtons_ant(vector<vector<int>> initial_grid, 
				  unsigned int initial_ant_x, 
                                  unsigned int initial_ant_y,
				  unsigned int n_iterations,
				  unsigned int initial_direction);

#endif
