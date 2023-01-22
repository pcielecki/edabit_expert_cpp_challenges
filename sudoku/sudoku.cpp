#include <array>
#include <algorithm>

#include "sudoku.hpp"

using rowcol = std::array<int, SUDOKU_FRAME_EDGE>;


bool validate_sudoku(sudoku_frame frame) {
    for(auto row: frame) {
        std::sort(row.begin(), row.end());
        if(std::adjacent_find(row.begin(), row.end()) != row.end())
            return false;
    }
    return true;
}
