/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (37.49%)
 * Likes:    2286
 * Dislikes: 106
 * Total Accepted:    264.2K
 * Total Submissions: 699.7K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int sum = 0;
        int start = 0;
        int end = 0;
        int rv = INT_MAX;
        while (start < nums.size() && end < nums.size()) {
            sum += nums[end];
            while (sum >= s && start <= end) {
                rv = min(rv, end - start + 1);
                sum -= nums[start];
                ++start;
            }
            ++end;
        }
        if (rv == INT_MAX) {
            return 0;
        }
        return rv;
    }
};
