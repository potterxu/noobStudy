#include <algorithm>
#include <vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> rv;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != nums[nums[i] - 1]) {
            swap(nums[nums[i] - 1], nums[i]);
            --i;
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            rv.push_back(i + 1);
        } 
    }
    return rv;
}