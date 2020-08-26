/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 *
 * https://leetcode.com/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (38.76%)
 * Likes:    1428
 * Dislikes: 63
 * Total Accepted:    63.3K
 * Total Submissions: 161.6K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * Your are given an array of positive integers nums.
 * Count and print the number of (contiguous) subarrays where the product of
 * all the elements in the subarray is less than k.
 * 
 * Example 1:
 * 
 * Input: nums = [10, 5, 2, 6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are: [10], [5],
 * [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly
 * less than k.
 * 
 * 
 * 
 * Note:
 * 0 < nums.length .
 * 0 < nums[i] < 1000.
 * 0 .
 * 
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        int product = 1;
        int start = 0;
        int end = 0;
        int rv = 0;
        while (end < nums.size() && start < nums.size()) {
            if (nums[end] >= k) {
                start = end + 1;
                end = start;
                product = 1;
                continue;
            }
            if (nums[end] * product >= k) {
                product /= nums[start];
                ++start;
                continue;
            }
            rv += end-start+1;
            product *= nums[end];
            ++end;
        }
        return rv;
    }
};