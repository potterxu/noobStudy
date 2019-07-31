#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    vector<int> rv;
    for (int i : nums1) {
        if (m.find(i) == m.end()) {
            m[i] = 1;
        } else {
            ++m[i];
        }
    }
    for (int i : nums2) {
        if (m.find(i) != m.end()) {
            if (m[i] > 0) { 
                m[i]--;
                rv.push_back(i);
            }
        }
    }
    return rv;
}