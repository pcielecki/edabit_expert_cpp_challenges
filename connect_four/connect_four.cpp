#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include <utility>
#include "connect_four.hpp"

using std::vector;
using std::string;
using std::array;
using std::pair;

enum class marker_colors {yellow, red, none};
const array<string, 3> results {"Yellow", "Red", "Draw"};

const unsigned int n_cols = 7;
const unsigned int n_rows = 6;
const array<string, n_cols> column_names = {"A", "B", "C", "D", "E", "F", "G"};
const unsigned int min_moves_to_win = 6;

enum class diagonal_types {left, right};

typedef vector<vector<marker_colors>> grid_t;

static unsigned int str_to_col_idx(const string& move) {
    unsigned int column_idx;
    try {
        string column_str = move.substr(0, 1);
        for(column_idx = 0; column_str != column_names.at(column_idx); ++column_idx); 
    } 
    catch(std::out_of_range) {
        throw InvalidMoveFormatException(move);
    }
    return column_idx;
}

static marker_colors str_to_color(const string& move) {
    string color_str;
    try {
        color_str = move.substr(2, string::npos);
        for(unsigned int color_idx = 0; color_str != results.at(color_idx); ++color_idx);
    }
    catch(std::out_of_range) {
        throw InvalidMoveFormatException(move);
    }
    return "Yellow" == color_str? marker_colors::yellow : marker_colors::red;
}

static marker_colors check_for_winner(const grid_t& collections) noexcept {
    for(const auto& collection: collections) {
        if(collection.size() < 4) 
            continue;

        for(marker_colors color: {marker_colors::red, marker_colors::yellow})
            for(auto frame_start = collection.begin(); frame_start != collection.end()-3; ++frame_start)
                if(std::all_of(frame_start, frame_start+4, [color](marker_colors marker){return marker == color;}))
                    return color;
    }
    return marker_colors::none;
}
//TODO does this wrapper really make sense or shall check_for_winner be invoked directly from find winner
static marker_colors check_column_winner(const grid_t& grid) noexcept {
    return check_for_winner(grid);
}

static marker_colors check_row_winner(const grid_t& grid) noexcept {
    grid_t grid_by_row(n_rows, vector<marker_colors>());
    for(unsigned int col_idx = 0; col_idx < n_cols; ++col_idx) {
        for(unsigned int row_idx = 0; row_idx < n_rows; ++row_idx) {
            grid_by_row.at(row_idx).push_back(row_idx < grid.at(col_idx).size()? 
                                              grid.at(col_idx).at(row_idx) : marker_colors::none);
        }
    }
    return check_for_winner(grid_by_row);
}

static marker_colors check_diagonal_winner(const grid_t& grid, diagonal_types diag_dir) noexcept {
    vector<pair<unsigned int, unsigned int>> diagonals_beginnings; 
    for(unsigned int i_row = 0; i_row <= n_rows-4; ++i_row)
        diagonals_beginnings.push_back(std::make_pair(diag_dir == diagonal_types::left? 0 : n_cols-1, i_row));
    for(unsigned int i_col = 1; i_col <= n_cols-4; ++i_col)
        diagonals_beginnings.push_back(std::make_pair(diag_dir == diagonal_types::left? 
                                                      i_col : n_cols-1-i_col, 0));
    grid_t subgrid_by_diagonals;
    for(auto xy: diagonals_beginnings) {
        subgrid_by_diagonals.push_back(vector<marker_colors>());
        while(xy.first < n_cols && xy.second < n_rows) {
            subgrid_by_diagonals.back().push_back(xy.second < grid.at(xy.first).size()? 
                                                  grid.at(xy.first).at(xy.second) : marker_colors::none);
            diag_dir == diagonal_types::left? xy.first++ : xy.first--; 
            xy.second++;
        }
    }
    return check_for_winner(subgrid_by_diagonals);
}

static marker_colors check_left_diagonal_winner(const grid_t& grid) noexcept {return check_diagonal_winner(grid, diagonal_types::left);}
static marker_colors check_right_diagonal_winner(const grid_t& grid) noexcept {return check_diagonal_winner(grid, diagonal_types::right);}

static marker_colors find_winner(const grid_t& grid) noexcept {
    marker_colors winner = marker_colors::none;
    for(auto win_checker: {check_column_winner, check_row_winner, check_left_diagonal_winner, check_right_diagonal_winner}) {
        winner = win_checker(grid);
        if(winner != marker_colors::none) 
            break;
        }
    return winner;
}

string connect_four(const vector<string>& moves) {
    grid_t grid(n_cols, vector<marker_colors>());
    marker_colors winner = marker_colors::none; 

    for(unsigned int move_idx = 0; move_idx < moves.size(); ++move_idx) {
        grid.at(str_to_col_idx(moves.at(move_idx))).push_back(str_to_color(moves.at(move_idx)));
        if(move_idx >= min_moves_to_win) { // it's not possible to win before the 7th move
            winner = find_winner(grid);
            if(marker_colors::none != winner)
                break;
        }
    }
    return results.at(static_cast<unsigned int>(winner));
}
