#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int rv = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        rv ^= nums[i];
    }
    return rv;
}