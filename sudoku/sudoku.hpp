#ifndef __sudoku__
#define __sudoku__

#include <vector>

#define SUDOKU_FRAME_EDGE 9
using sudoku_frame = std::vector<std::vector<int>>;

bool validate_sudoku(sudoku_frame frame);

#endif
