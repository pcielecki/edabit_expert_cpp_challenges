#include <array>
#include <algorithm>

#include "sudoku.hpp"

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
    return true;
}
