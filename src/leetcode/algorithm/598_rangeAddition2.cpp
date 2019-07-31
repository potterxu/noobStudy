#include <vector>
using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    for (auto &vec : ops) {
        if (vec[0] < m) {
            m = vec[0];
        }
        if (vec[1] < n) {
            n = vec[1];
        }
    }
    return m * n;
}