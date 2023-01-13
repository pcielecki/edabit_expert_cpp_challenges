#include <set>
#include <utility>
using std::set;
using std::pair;

class Island {
public:
    Island(pair<int, int> first_point){points.insert(first_point);}
    bool is_it_my_point(pair<int, int> point) const;
    void add_point(pair<int, int> point);
    void merge_island(Island& island2);
    int get_size() const;
    friend bool operator<(const Island& i1, const Island& i2) {return i1.points.size() < i2.points.size();}
    Island& operator+=(const Island& island2) {
        if(&island2 != this)
            for(auto& point: island2.points)
                points.insert(point);
        return *this;
    }

private:
    set<pair<int, int>> points;
};


