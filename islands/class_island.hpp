#include <vector>
#include <utility>
using std::vector;
using std::pair;

class Island {
public:
    Island(pair<int, int> first_point){points.push_back(first_point);}
    bool is_it_my_point(pair<int, int> point) const;
    void add_point(pair<int, int> point);
    void merge_island(Island& island2);
    int get_size() const;

private:
    vector<pair<int, int>> points;
};


