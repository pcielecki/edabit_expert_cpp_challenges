#include <vector>
#include <algorithm>
#include <utility>

#include "islands.hpp"
#include "class_island.hpp"

using std::vector;
using std::pair;
using std::make_pair;

int _get_first_nonzero_line(int** map, int xsize, int ysize) {
    for(int y=0; y<ysize; y++)
    {
        for(int x=0; x<xsize; x++) {
            if(map[y*ysize+x] != 0) return y;
        }
    }
    return ysize;
}

int get_largest_island_size(int **map, int xsize, int ysize)
{
    vector<Island> islands;

    for(int y=_get_first_nonzero_line(map, xsize, ysize); y<ysize; ++y) { //start the loop at first nonzero lines
        for(int x=0; x<xsize; ++x) {
            if(!map[y*ysize+x])  // skip zeros
               continue;
            auto point = make_pair(x, y);

            vector<Island*> islands_sharing_the_point;

            for(auto& island: islands) {
                if(island.is_it_my_point(point)) {
                    island.add_point(point);
                    islands_sharing_the_point.push_back(&island);
                }
            }
            if(islands_sharing_the_point.empty())
                islands.push_back(Island(point));
            for(const Island* p_island: islands_sharing_the_point)
                *islands_sharing_the_point.at(0) += *p_island;
        }
    }
    return std::max_element(islands.begin(), islands.end())->get_size();
}

