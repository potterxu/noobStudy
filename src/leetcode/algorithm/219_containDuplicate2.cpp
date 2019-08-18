#include <unordered_map>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int start = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (m[nums[i]]) {
            return true;
        }
        m[nums[i]] = 1;
        if (i - start == k) {
            m[nums[start]] = 0;
            ++start;
        }
    }
    return false;
}