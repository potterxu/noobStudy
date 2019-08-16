#include <vector>
using namespace std;

int dominantIndex(vector<int>& nums) {
    int second = 0;
    int rv = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (rv == -1) {
            rv = i;
            continue;
        }
        if (nums[i] > nums[rv]) {
            second = nums[rv];
            rv = i;
        } else {
            second = max(second, nums[i]);
        }
    }
    if (nums[rv] >= second + second) {
        return rv;
    }
    return -1;
}