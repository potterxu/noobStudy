#include <vector>
using namespace std;

bool checkPossibility_modifyInput(vector<int>& nums) {
    if (nums.size() < 3) {
        return true;
    }
    bool ok = true;
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i+1]) {
            if (!ok) {
                return false;
            }
            ok = false;
            if (i == 0) {
                nums[i] = nums[i+1];
                continue;
            } else {
                if (nums[i+1] < nums[i-1]) {
                    nums[i+1] = nums[i];
                } else {
                    nums[i] = nums[i+1];
                }
            }
        }
    }
    return true;
}
bool checkPossibility_noModifyInput(vector<int>& nums) {
    if (nums.size() < 3) {
        return true;
    }
    bool ok = true;
    int pre = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (pre > nums[i]) {
            if (!ok) {
                return false;
            }
            ok = false;
            if (i - 2 < 0) {
                pre = nums[i];
            } else if (nums[i-2] > nums[i]) {
                pre = nums[i-1];
            } else {
                pre = nums[i];
            }
        } else {
            pre = nums[i];
        }
    }
    return true;
}