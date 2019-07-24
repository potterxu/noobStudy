#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int zeroCount = 0;
    int ptr = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i]) {
            nums[ptr] = nums[i];
            ++ptr;
        } else {
            ++zeroCount;
        }
    }
    for (int i = nums.size() - zeroCount; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}