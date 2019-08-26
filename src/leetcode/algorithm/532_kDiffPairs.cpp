#include <unordered_map>
#include <vector>
using namespace std;

int findPairs(vector<int>& nums, int k) {
    if (k < 0) {
        return 0;
    }
    unordered_map<int, int> m;
    int rv = 0;
    for (int i : nums) {
        ++m[i];
    }
    for (auto &p : m) {
        printf("%d, %d\n", p.first, p.second);
        if (k == 0) {
            if (p.second >= 2) {
                ++rv;
            }
        } else {
            if (m.count(p.first + k)) {
                ++rv;
            }
        }
    }
    return rv;
}