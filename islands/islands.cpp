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

    for(int y=_get_first_nonzero_line(map, xsize, ysize); y<ysize; ++y) {
    for(int x=0; x<xsize; ++x) {
        if(!map[y*ysize+x]) 
           continue;

        auto point = make_pair(x, y);

        vector<Island*> islands_sharing_the_point;

        if(islands.empty())  // initial case - no islands // nieprawda, jesli zadna wyspa sie nie przyzna tez powinno wtedy tu wejsc
        {
            islands.push_back(Island(point));
        }
        else { //once there is >= island
            for(auto island: islands) {
                if(island.is_it_my_point(point)) {
                    island.add_point(point);
                    islands_sharing_the_point.push_back(&island);
                }
            }
            if(islands_sharing_the_point.size() > 1) { //if >=2 islands share the point
                for(unsigned int idx = 1; idx < islands_sharing_the_point.size(); ++idx) {
                    islands_sharing_the_point.at(0)->merge_island(*islands_sharing_the_point.at(idx));
                }
            // code for merging islands
            }
        }
    }
    }
    return std::max_element(
        islands.begin(), 
        islands.end(), 
        [](const Island& island1, const Island& island2) 
            {return island1.get_size() < island2.get_size();})->get_size();
}

