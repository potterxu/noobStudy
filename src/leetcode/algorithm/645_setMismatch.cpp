#include <vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        while (nums[i] != i+1) {
            if (nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                break;
            }
        }
    }
    vector<int> rv(2);
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            rv[0] = nums[i];
            rv[1] = i+1;
        }
    }
    return rv;
}