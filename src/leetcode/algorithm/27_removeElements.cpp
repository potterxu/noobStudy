#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j) {
        if (nums[i] != val) {
            ++i;
            continue;
        }
        if (nums[j] == val) {
            --j;
            continue;
        }
        swap(nums[i], nums[j]);
    }
    return i;
}