#include <vector>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}
int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int ptr = 0;
    int rv = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] <= nums[i-1]) {
            ptr = i;
        } else {
            rv = max(rv, i - ptr + 1);
        }
    }
    return rv;
}