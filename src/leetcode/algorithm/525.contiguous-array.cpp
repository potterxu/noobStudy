/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (42.47%)
 * Likes:    2243
 * Dislikes: 121
 * Total Accepted:    164.2K
 * Total Submissions: 384.1K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1. 
 * 
 * 
 * Example 1:
 * 
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * 
 * 
 * Note:
 * The length of the given binary array will not exceed 50,000.
 * 
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        int rv = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                --sum;
            } else {
                ++sum;
            }
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            } else {
                rv = max(rv, i - m[sum]);
            }
        }
        return rv;
    }
};
