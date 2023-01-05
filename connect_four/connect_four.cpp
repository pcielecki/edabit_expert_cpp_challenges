#include <vector>
#include <array>
#include <string>
#include <utility>

using std::vector;
using std::string;
using std::array;
using std::pair;

enum class marker_colors {yellow, red, none};
const array<string, 3> results {"Yellow", "Red", "Draw"};

const unsigned int n_cols = 7;
const array<string, n_cols> columns = {"A", "B", "C", "D", "E", "F", "G"};
enum class columns_marks {A = 0, B, C, D, E, F, G, err};

const unsigned int n_rows = 6;

typedef vector<vector<marker_colors>> grid_t;

static columns_marks str_to_col(const string& move) {
    string col_str = move.substr(0, 1);
    for(unsigned int idx = 0; idx < n_cols; ++idx) {
        if(col_str == columns.at(idx))
                return static_cast<columns_marks>(idx);
    }
    return columns_marks::err;
}

static marker_colors str_to_color(const string& move) {
    string color_str = move.substr(2, string::npos);
    return color_str == "Yellow"? marker_colors::yellow : marker_colors::red;
}

static marker_colors check_for_winner(const grid_t& collections) {
    marker_colors winner(marker_colors::none);

    for(const auto& collection: collections) {
        if(collection.empty()) 
            continue;

        marker_colors color_checked = collection.at(0);
        unsigned int n_discs_matching = 0;
        for(const auto& marker: collection) {
            if(color_checked == marker) {
                if(++n_discs_matching == 4) {
                    winner = color_checked;
                    break;
                }
            }
            color_checked = marker;
        }
        if(winner != marker_colors::none)
            break;
    }
    return winner;
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

static marker_colors check_diagonal_winner(const grid_t& grid) {
    //remember both left n right
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

static marker_colors find_winner(const grid_t& grid) {
    marker_colors winner = check_column_winner(grid);
    if(marker_colors::none != winner) return winner;
    winner = check_row_winner(grid);
    if(marker_colors::none != winner) return winner;
    winner = check_diagonal_winner(grid);

    return winner;
}

// TODO does casting back and forth to column_marks makes any sense?
string connect_four(const vector<string>& moves) {
    grid_t grid(n_cols, vector<marker_colors>());
    marker_colors winner = marker_colors::none; 

    for(unsigned int move_idx = 0; move_idx < moves.size(); ++move_idx) {
        grid.at(static_cast<unsigned int>(str_to_col(moves.at(move_idx)))).push_back(str_to_color(moves.at(move_idx)));
        if(move_idx >= 6) { // it's not possible to win before the 7th move
            winner = find_winner(grid);
            if(marker_colors::none != winner)
                break;
        }
    }
    return results.at(static_cast<unsigned int>(winner));
}
