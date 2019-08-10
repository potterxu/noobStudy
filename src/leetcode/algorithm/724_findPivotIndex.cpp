#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    if (nums.size() == 1) {
        return 0;
    }
    for (int i = 1; i < nums.size(); ++i) {
        nums[i] += nums[i-1];
    }
    if (nums[nums.size() - 1] - nums[0] == 0) {
        return 0;
    }
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[nums.size() - 1] - nums[i] == nums[i-1]) {
            return i;
        }
    }
    return -1;
}