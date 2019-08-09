#include <vector>
#include <unordered_map>
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int, int> m;
    int rv = 0;
    for (auto &v : dominoes) {
        if (v[0] < v[1]) {
            swap(v[0], v[1]);
        }
        int i = v[0] * 10 + v[1];
        rv += m[i];
        ++m[i];
    }
    return rv;
}