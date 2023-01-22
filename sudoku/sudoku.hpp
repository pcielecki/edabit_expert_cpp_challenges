#ifndef __sudoku__
#define __sudoku__

#include <array>

#define SUDOKU_FRAME_EDGE 9
using sudoku_frame = std::array<std::array<int, SUDOKU_FRAME_EDGE>, SUDOKU_FRAME_EDGE>;

bool validate_sudoku(sudoku_frame frame);

#endif
