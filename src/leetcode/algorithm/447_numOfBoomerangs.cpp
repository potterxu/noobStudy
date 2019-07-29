#include <unordered_map>
#include <vector>
using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) {
    unordered_map<int, int> m;
    int rv = 0;
    for (auto &p1 : points) {
        m.clear();
        for (auto &p2 : points) {
            int dis = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
            if (m.find(dis) == m.end()) {
                m[dis] = 1;
            } else {
                rv += m[dis] + m[dis];
                ++m[dis];
            }
        }
    }
    return rv;
}