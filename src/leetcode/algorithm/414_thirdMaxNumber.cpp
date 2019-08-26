#include <vector>
#include <algorithm>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}
int thirdMax(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        return max(nums[0], nums[1]);
    }
    vector<int> v;
    for (int i : nums) {
        if (v.empty()) {
            v.push_back(i);
        } else {
            int ok = true;
            for (int j = 0; j < v.size(); ++j) {
                if (i > v[j]) {
                    swap(i, v[j]);
                } else if (i == v[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && v.size() < 3) {
                v.push_back(i);
            }
        }
    }
    if (v.size() == 3) {
        return v[2];
    }
    return v[0];
}