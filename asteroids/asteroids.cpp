#include <vector>
#include <cmath>
#include <algorithm>
using std::vector;
using std::abs;

vector<int> calculate_asteroids(vector<int> asteroids) {
    for(vector<int>::iterator it = asteroids.begin(); it < asteroids.end()-1;) {
        if(*it > 0 && *(it+1) < 0) {
            if(-*it == *(it+1))
                asteroids.erase(it, it+2);
            else
                asteroids.erase(*it < -*(it+1)? it : it+1);
            it = asteroids.begin();
        }
        else ++it;
    }
    return asteroids;
}
