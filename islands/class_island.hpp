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
    friend bool operator<(const Island& i1, const Island& i2) {return i1.points.size() < i2.points.size();}
    Island& operator+=(const Island& island2) 
    {
        points.insert(points.end(), island2.points.begin(), island2.points.end());
        return *this;
    }

private:
    vector<pair<int, int>> points;
};


