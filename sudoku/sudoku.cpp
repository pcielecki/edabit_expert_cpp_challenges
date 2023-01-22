#include <vector>
#include <algorithm>

#include "sudoku.hpp"

using rowcol = std::vector<int>;

static bool duplicates_present(const sudoku_frame& collections) {
    return std::any_of(collections.begin(), collections.end(), [](rowcol segment) {
        std::sort(segment.begin(), segment.end());
        return std::adjacent_find(segment.begin(), segment.end()) != segment.end();
    });
}
sudoku_frame get_frame_by_column(const sudoku_frame& frame) {
    sudoku_frame frame_by_column (9, rowcol());
    for(unsigned int column_idx = 0; column_idx < SUDOKU_FRAME_EDGE; ++column_idx)
        for(const rowcol& row: frame)
            frame_by_column.at(column_idx).push_back(row.at(column_idx));
    return frame_by_column;
}

bool validate_sudoku(sudoku_frame frame) {
    std::vector<sudoku_frame> frames {frame, get_frame_by_column(frame)};
    return !std::any_of(frames.begin(), frames.end(), duplicates_present);
}
