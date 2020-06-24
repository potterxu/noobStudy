/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.82%)
 * Likes:    2042
 * Dislikes: 139
 * Total Accepted:    467.2K
 * Total Submissions: 1M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int sum = nums[i] + nums[i+1] + nums[i+2];
            if (sum > target) {
                int diff = sum - target;
                if (abs(diff) < abs(minDiff)) {
                    minDiff = diff;
                }
                continue;
            } else if (sum == target) {
                return target;
            }
            sum = nums[i] + nums[nums.size()-1] + nums[nums.size()-2];
            if (sum < target) {
                int diff = sum - target;
                if (abs(diff) < abs(minDiff)) {
                    minDiff = diff;
                }
                continue;
            } else if (sum == target) {
                return target;
            }
            int start = i+1; 
            int end = nums.size() - 1;
            while (start < end) {
                if (start > i+1 && nums[start] == nums[start-1]) {
                    ++start;
                    continue;
                }
                if (end < nums.size() -1 && nums[end] == nums[end+1]) {
                    --end;
                    continue;
                }
                sum = nums[i] + nums[start] + nums[end];
                int diff = sum - target;
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    --end;
                } else {
                    ++start;
                }
                if (abs(diff) < abs(minDiff)) {
                    minDiff = diff;
                }
            }
        }
        return target + minDiff;
    }
};
