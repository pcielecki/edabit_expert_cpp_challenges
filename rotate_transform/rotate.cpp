#include <vector>
#include <algorithm>
#include "rotate.hpp"

using std::vector;

void rotate_transform(vector<vector<int>>& arr, int no_of_rotations)
{
    if(!no_of_rotations%4)
        return;
    else if(no_of_rotations < 0)
        no_of_rotations = std::abs(no_of_rotations) + 2;

    unsigned int arr_size = arr.size(); 
    vector<vector<int>> rotated_arr(arr_size, vector<int>(arr_size, 0));

    for(unsigned int y = 0; y < arr_size; ++y) {
        for(unsigned int x = 0; x < arr_size; ++x) {
            switch(no_of_rotations) {
                case 1:
                    rotated_arr.at(x).at(arr_size-1-y) = arr.at(y).at(x);
                    break;
                case 2:
                    rotated_arr.at(arr_size-1-y).at(arr_size-1-x) = arr.at(y).at(x);
                    break;
                case 3:
                    rotated_arr.at(arr_size-1-x).at(y) = arr.at(y).at(x);
                    break;
            }
        }
    }
    arr = rotated_arr;
}
