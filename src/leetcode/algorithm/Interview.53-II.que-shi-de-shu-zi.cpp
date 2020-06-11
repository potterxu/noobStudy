class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.back() == nums.size()-1) {
            return nums.size();
        }
        if (nums[0] != 0) {
            return 0;
        }
        int start = 1;
        int end = nums.size() - 1;
        while (start < end) {
            int mid = (start+end)/2;
            if (nums[mid] == mid) {
                start = mid + 1;
                if (nums[start] != start) {
                    return start;
                }
            } else {
                end = mid - 1;
                if (nums[end] == end) {
                    return end + 1;
                }
            }
        }
        return end;
    }
};
