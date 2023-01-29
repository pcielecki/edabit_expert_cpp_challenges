#include <vector>
#include <algorithm>
using std::min;
using std::max;
using std::vector;

vector<vector<unsigned int>> make_dartboard(unsigned int size) {
    vector<vector<unsigned int>> dartboard(size, vector<unsigned int>());
    for(unsigned int row_idx = 0; row_idx < size; ++row_idx)
        for(unsigned int col_idx = 0; col_idx < size; ++col_idx)
            dartboard.at(row_idx).push_back(min(min(col_idx+1, size-col_idx), min(row_idx+1, size-row_idx)));
    return dartboard;
}
