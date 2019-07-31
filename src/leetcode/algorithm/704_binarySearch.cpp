#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    if (target > nums[nums.size() - 1] || target < nums[0]) {
        return -1;
    }
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (target < nums[mid]) {
            end = mid - 1;
        } else if (target > nums[mid]) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}