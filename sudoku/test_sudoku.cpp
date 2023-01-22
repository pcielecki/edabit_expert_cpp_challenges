#include <gtest/gtest.h>
#include "sudoku.hpp"

TEST(SudokuSuite, SudokuTestPassCorrectFrame) {
    sudoku_frame frame = {{
        { 1, 5, 2, 4, 8, 9, 3, 7, 6 },
        { 7, 3, 9, 2, 5, 6, 8, 4, 1 },
        { 4, 6, 8, 3, 7, 1, 2, 9, 5 },
        { 3, 8, 7, 1, 2, 4, 6, 5, 9 },
        { 5, 9, 1, 7, 6, 3, 4, 2, 8 },
        { 2, 4, 6, 8, 9, 5, 7, 1, 3 },
        { 9, 1, 4, 6, 3, 7, 5, 8, 2 },
        { 6, 2, 5, 9, 4, 8, 1, 3, 7 },
        { 8, 7, 3, 5, 1, 2, 9, 6, 4 }
    }};
    ASSERT_EQ(true, validate_sudoku(frame));
}

TEST(SudokuSuite, SudokuTestFailOnRepetitionInRow) {
    // double 1 in row 0
    sudoku_frame frame = {{
        { 1, 1, 2, 4, 8, 9, 3, 7, 6 },
        { 7, 3, 9, 2, 5, 6, 8, 4, 1 },
        { 4, 6, 8, 3, 7, 1, 2, 9, 5 },
        { 3, 8, 7, 1, 2, 4, 6, 5, 9 },
        { 5, 9, 1, 7, 6, 3, 4, 2, 8 },
        { 2, 4, 6, 8, 9, 5, 7, 1, 3 },
        { 9, 1, 4, 6, 3, 7, 5, 8, 2 },
        { 6, 2, 5, 9, 4, 8, 1, 3, 7 },
        { 8, 7, 3, 5, 1, 2, 9, 6, 4 }
    }};
    ASSERT_EQ(false, validate_sudoku(frame));
}

TEST(SudokuSuite, SudokuTestFailOnRepetitionInColumn) {
    // double 3 in column 6
    sudoku_frame frame = {{
        { 1, 5, 2, 4, 8, 9, 3, 7, 6 },
        { 7, 3, 9, 2, 5, 6, 8, 4, 1 },
        { 4, 6, 8, 0, 7, 1, 3, 9, 5 },
        { 3, 8, 7, 1, 2, 4, 6, 5, 9 },
        { 5, 9, 1, 7, 6, 3, 4, 2, 8 },
        { 2, 4, 6, 8, 9, 5, 7, 1, 3 },
        { 9, 1, 4, 6, 3, 7, 5, 8, 2 },
        { 6, 2, 5, 9, 4, 8, 1, 3, 7 },
        { 8, 7, 3, 5, 1, 2, 9, 6, 4 }
    }};
    ASSERT_EQ(false, validate_sudoku(frame));
}

TEST(SudokuSuite, SudokuTestFailOnRepetitionIn3x3Block) {
    //double 5 in the bottom right 3x3 square
    sudoku_frame frame = {{
        { 1, 5, 2, 4, 8, 9, 3, 7, 6 },
        { 7, 3, 9, 2, 5, 6, 8, 4, 1 },
        { 4, 6, 8, 3, 7, 1, 2, 9, 5 },
        { 3, 8, 7, 1, 2, 4, 6, 0, 9 },
        { 5, 9, 1, 7, 6, 3, 4, 2, 8 },
        { 2, 4, 6, 8, 9, 5, 7, 1, 3 },
        { 9, 1, 4, 6, 3, 7, 5, 8, 2 },
        { 6, 2, 5, 9, 4, 8, 1, 5, 7 },
        { 8, 7, 3, 5, 1, 2, 9, 6, 4 }
    }};
    ASSERT_EQ(false, validate_sudoku(frame));
}
