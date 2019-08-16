#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (target > nums[mid]) {
            start = mid + 1;
        } else if (target == nums[mid]) {
            return mid;
        } else {
            end = mid - 1;
        }
    }
    return start;
}