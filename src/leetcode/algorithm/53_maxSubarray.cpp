#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int rv = -0x7fffffff, sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        rv = max(sum, rv);
        sum = max(sum, 0);
    }
    return rv;
}