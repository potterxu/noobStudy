#include <vector>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    bool ok = true;
    int minimum = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (!ok) {
            minimum = min(minimum, nums[i]);
            continue;
        }
        if (nums[i-1] > nums[i]) {
            ok = false;
            minimum = nums[i];
        }
    }
    if (ok) {
        return 0;
    }
    ok = true;
    int maximum = 0;
    for (int i = nums.size() - 2; i > -1; --i) {
        if (!ok) {
            maximum = max(nums[i], maximum);
            continue;
        }
        if (nums[i+1] < nums[i]) {
            ok = false;
            maximum = nums[i];
        }
    }
    int maxI = 0;
    int minI = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > minimum) {
            minI = i;
            break;
        }
    }
    for (int i = nums.size() - 1; i > -1; --i) {
        if (nums[i] < maximum) {
            maxI = i;
            break;
        }
    }
    return maxI - minI + 1;
}