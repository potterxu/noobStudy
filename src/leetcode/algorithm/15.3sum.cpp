/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.20%)
 * Likes:    6655
 * Dislikes: 792
 * Total Accepted:    889.4K
 * Total Submissions: 3.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void twoSum(vector<int>& nums, int i, int sum, vector<vector<int>>& rv) {
        int start = i;
        int end = nums.size() - 1;
        while (start < end) {
            while (start < end && start > i && nums[start] == nums[start-1]) {
                ++start;
            }
            while (end < nums.size()-1 && start < end && nums[end] == nums[end+1]) {
                --end;
            }
            if (start >= end) {
                break;
            }
            int totalSum = nums[start] + nums[end];
            if (totalSum == sum) {
                rv.push_back({-sum, nums[start], nums[end]});
                ++start;
                --end;
            } else if (totalSum < sum) {
                ++start;
            } else {
                --end;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rv;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums.front() > 0 || nums.back() < 0) {
            return rv;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            twoSum(nums, i+1, -nums[i], rv);
        }
        return rv;
    }
};
// @lc code=end
