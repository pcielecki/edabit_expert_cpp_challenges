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
static sudoku_frame get_frame_by_column(const sudoku_frame& frame) {
    sudoku_frame frame_by_column (SUDOKU_FRAME_EDGE, rowcol());
    for(unsigned int column_idx = 0; column_idx < SUDOKU_FRAME_EDGE; ++column_idx)
        for(const rowcol& row: frame)
            frame_by_column.at(column_idx).push_back(row.at(column_idx));
    return frame_by_column;
}
static sudoku_frame get_frame_by_3x3_blocks(const sudoku_frame& frame) {
    const unsigned int block_edge = 3;
    sudoku_frame frame_by_3x3_blocks (SUDOKU_FRAME_EDGE, rowcol());

    for(unsigned int block_idx = 0; block_idx < SUDOKU_FRAME_EDGE; ++block_idx) {
        unsigned int min_row_idx = (block_idx / block_edge) * block_edge;
        unsigned int min_col_idx = (block_idx % block_edge) * block_edge;
        for(unsigned int i_row_offset = 0; i_row_offset < block_edge; ++i_row_offset) {
            std::vector<int>& v = frame_by_3x3_blocks.at(block_idx);
            v.insert(
                frame_by_3x3_blocks.at(block_idx).end(),
                frame.at(min_row_idx+i_row_offset).begin()+min_col_idx,
                frame.at(min_row_idx+i_row_offset).begin()+min_col_idx + block_edge);
        }
    }
    return frame_by_3x3_blocks;
}
bool validate_sudoku(sudoku_frame frame) {
    std::vector<sudoku_frame> frames {frame, get_frame_by_column(frame), get_frame_by_3x3_blocks(frame)};
    return !std::any_of(frames.begin(), frames.end(), duplicates_present);
}
