#include "class_island.hpp"

#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

bool Island::is_it_my_point(pair<int, int> point) const
{
    return std::any_of(
        points.begin(), points.end(),
        [point](pair<int, int> my_point) {
            return (point.second - my_point.second) <= 1 && abs(point.first - my_point.first) <= 1; }
    );
}

void Island::add_point(pair<int, int> point) 
{
    this->points.insert(point); 
}

int Island::get_size() const { return points.size(); }


