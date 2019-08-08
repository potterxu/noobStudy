#include <algorithm>
#include <vector>

using namespace std;
int findLHS(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int pre = 0;
    int cur = 1;
    int rv = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i-1]) {
            ++cur;
        } else {
            if (pre != 0) {
                rv = max(rv, pre+cur);
            }
            if (nums[i] - nums[i-1] == 1) {
                pre = cur;
            } else {
                pre = 0;
            }
            cur = 1;
        }
    }
    if (pre != 0 && cur != 0) {
        rv = max(rv, pre+cur);
    }
    return rv;
}