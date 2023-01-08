#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include <utility>

using std::vector;
using std::string;
using std::array;
using std::pair;

enum class marker_colors {yellow, red, none};
const array<string, 3> results_str {"Yellow", "Red", "Draw"};

const unsigned int n_cols = 7;
const unsigned int n_rows = 6;
const array<string, n_cols> columns_str = {"A", "B", "C", "D", "E", "F", "G"};
const unsigned int min_moves_to_win = 6;

typedef vector<vector<marker_colors>> grid_t;

static unsigned int str_to_col_idx(const string& move) {
    string column_str = move.substr(0, 1);
    unsigned int column_idx = 0;
    for(column_idx = 0; column_str != columns_str.at(column_idx); ++column_idx); 
    return column_idx;
}

static marker_colors str_to_color(const string& move) {
    string color_str = move.substr(2, string::npos);
    return color_str == "Yellow"? marker_colors::yellow : marker_colors::red;
}

static marker_colors check_for_winner(const grid_t& collections) {
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
static marker_colors check_column_winner(const grid_t& grid) {
    return check_for_winner(grid);
}

static marker_colors check_row_winner(const grid_t& grid) {
    grid_t grid_by_row(n_rows, vector<marker_colors>());
    for(unsigned int col_idx = 0; col_idx < n_cols; ++col_idx) {
        for(unsigned int row_idx = 0; row_idx < n_rows; ++row_idx) {
            grid_by_row.at(row_idx).push_back(row_idx < grid.at(col_idx).size()? 
                                              grid.at(col_idx).at(row_idx) : marker_colors::none);
        }
    }
    return check_for_winner(grid_by_row);
}

static marker_colors check_left_diagonal_winner(const grid_t& grid) {
    vector<pair<unsigned int, unsigned int>> diagonals_beginnings; 
    for(unsigned int i_row = 0; i_row <= n_rows-4; ++i_row)
        diagonals_beginnings.push_back(std::make_pair(0, i_row));
    for(unsigned int i_col = 1; i_col <= n_cols-4; ++i_col)
        diagonals_beginnings.push_back(std::make_pair(i_col, 0));

    grid_t diagonals;
    for(auto xy: diagonals_beginnings) {
        diagonals.push_back(vector<marker_colors>());
        while(xy.first < n_cols && xy.second < n_rows) {
            diagonals.back().push_back(
                    xy.second < grid.at(xy.first).size()? 
                    grid.at(xy.first).at(xy.second) : marker_colors::none);
            xy.first++; xy.second++;
        }
    }
    return check_for_winner(diagonals);
}

static marker_colors check_right_diagonal_winer(const grid_t& grid) {
    vector<pair<unsigned int, unsigned int>> diagonals_beginnings; 
    for(unsigned int i_row = 0; i_row <= n_rows-4; ++i_row)
        diagonals_beginnings.push_back(std::make_pair(n_cols-1, i_row));
    for(unsigned int i_col = 3; i_col < n_cols-1; ++i_col)
        diagonals_beginnings.push_back(std::make_pair(i_col, 0));

    grid_t diagonals;
    for(auto xy: diagonals_beginnings) {
        diagonals.push_back(vector<marker_colors>());
        while(xy.first < n_cols && xy.second < n_rows) {
            diagonals.back().push_back(
                    xy.second < grid.at(xy.first).size()? 
                    grid.at(xy.first).at(xy.second) : marker_colors::none);
            xy.first--; xy.second++;
        }
    }
    return check_for_winner(diagonals);
}

static marker_colors find_winner(const grid_t& grid) {
    marker_colors winner = marker_colors::none;
    for(auto win_checker: {check_column_winner, check_row_winner, check_left_diagonal_winner}) {
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
    return results_str.at(static_cast<unsigned int>(winner));
}
