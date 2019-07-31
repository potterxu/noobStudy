#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int rv = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
        rv ^= i;
        rv ^= nums[i];
    }
    return rv;
}