#include <unordered_map>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> rv;
    unordered_map<int, int> m;
    for (int i : nums1) {
        m[i] = 0;
    }
    for (int i : nums2) {
        if (m.find(i) != m.end()) {
            m[i] = 1;
        }
    }
    for (auto p : m) {
        if (p.second > 0) {
            rv.push_back(p.first);
        }
    }
    return rv;
}