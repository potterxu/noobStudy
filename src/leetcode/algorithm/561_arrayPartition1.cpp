#include <vector>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int rv = 0;
    for (int i = 0; i < nums.size(); i+=2) {
        rv += nums[i];
    }
    return rv;
}