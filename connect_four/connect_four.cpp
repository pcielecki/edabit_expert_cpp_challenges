#include <vector>
#include <array>
#include <string>

using std::vector;
using std::string;
using std::array;

enum class marker_colors {yellow, red, none};
const array<string, 3> results {"Yellow", "Red", "Draw"};

const unsigned int n_cols = 7;
const array<string, n_cols> columns = {"A", "B", "C", "D", "E", "F", "G"};
enum class columns_marks {A = 0, B, C, D, E, F, G, err};

const unsigned int n_rows = 6;

typedef array<vector<marker_colors>, n_cols> grid_t;

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

static marker_colors check_column_winner(const grid_t& grid) {
    for(const vector<marker_colors>& column: grid) {
        if(column.size() < 4)
            continue;
        else {
            marker_colors color_checked = column.at(0);
            unsigned int n_discs_matching = 0;
            for(const auto& row: column) {
                if(color_checked == row) {
                    if(++n_discs_matching == 4) {
                        return color_checked;
                    }
                }
                color_checked = row;
                }
            }
    }
    return marker_colors::none;
}

static marker_colors check_row_winner(const grid_t& grid) {
    for(unsigned int row_idx = 0; row_idx < n_rows; ++row_idx) {
        array<marker_colors, n_cols> row;
        for(unsigned int col_idx = 0; col_idx < n_cols; ++col_idx) {
            row.at(col_idx) = row_idx < grid.at(col_idx).size()? grid.at(col_idx).at(row_idx) : marker_colors::none;
        }
        marker_colors color_checked = row.at(0);
        unsigned int n_discs_matching = 0;
        for(const marker_colors& marker: row) {
            if(color_checked == marker) {
                if(++n_discs_matching == 4) {
                    return color_checked;
                }
            }
            color_checked = marker;
        }
    }
    return marker_colors::none;
}

static marker_colors find_winner(const grid_t& grid) {
    marker_colors winner = check_column_winner(grid);
    if(marker_colors::none != winner) return winner;
    winner = check_row_winner(grid);

    return winner;
}

// TODO does casting back and forth to column_marks makes any sense?
string connect_four(const vector<string>& moves) {
    grid_t grid;
    marker_colors winner = marker_colors::none; 

    for(const string& move: moves) {
        grid.at(static_cast<unsigned int>(str_to_col(move))).push_back(str_to_color(move));
        winner = find_winner(grid);
        if(marker_colors::none != winner)
            break;
    }
    return results.at(static_cast<unsigned int>(winner));
}
