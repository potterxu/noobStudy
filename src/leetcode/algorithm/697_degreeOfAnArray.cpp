#include<unordered_map>
#include<vector>
using namespace std;

int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, vector<int>> m;
    int rv = 0x7fffffff;
    int degree = 1;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(nums[i]) == m.end()) {
            m[nums[i]] = {1, i, i};
        } else {
            ++m[nums[i]][0];
            m[nums[i]][2] = i;
        }
        if (m[nums[i]][0] > degree) {
            degree = m[nums[i]][0];
            rv = m[nums[i]][2] - m[nums[i]][1] + 1;
        } else if (m[nums[i]][0] == degree) {
            if (m[nums[i]][2] - m[nums[i]][1] + 1 < rv) {
                rv = m[nums[i]][2] - m[nums[i]][1] + 1;
            }
        }
    }
    return rv;
}