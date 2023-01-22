#include <array>
#include <vector>
#include <algorithm>

#include "sudoku.hpp"

using std::vector;
using rowcol = std::array<int, SUDOKU_FRAME_EDGE>;

static bool duplicates_present(rowcol collection) {
        std::sort(collection.begin(), collection.end());
        return std::adjacent_find(collection.begin(), collection.end()) != collection.end();
}

bool validate_sudoku(sudoku_frame frame) {
    for(auto row: frame) {
        if(duplicates_present(row))
            return false;
    }
    for(unsigned int col_idx = 0; col_idx < SUDOKU_FRAME_EDGE; ++col_idx) {
        rowcol column;
        for(unsigned int row_idx = 0; row_idx < SUDOKU_FRAME_EDGE; ++row_idx)
            column.at(row_idx) = frame.at(row_idx).at(col_idx);
        if(duplicates_present(column)) return false;
    }
    return true;
}
