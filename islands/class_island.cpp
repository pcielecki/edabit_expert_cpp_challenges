#include "class_island.hpp"

#include <utility>
#include <vector>
#include <cmath>

using std::vector;

bool Island::is_it_my_point(pair<int, int> point) const
{
    for(auto my_point: points)
    {
        if(my_point.second < point.second-1) // same or previous line
            continue;

        if(abs(my_point.first - point.first) <= 1)
            return true;
    }
    return false;
}

void Island::add_point(pair<int, int> point) 
{
    this->points.push_back(point); 
}

void Island::merge_island(Island& island2) 
{
    points.insert(points.end(), island2.points.begin(), island2.points.end());
}
int Island::get_size() const { return points.size(); }

