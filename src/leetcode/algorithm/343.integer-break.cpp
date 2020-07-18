/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (49.79%)
 * Likes:    1070
 * Dislikes: 226
 * Total Accepted:    109.6K
 * Total Submissions: 217.8K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */

class Solution {
public:
    int integerBreak(int n) {
        vector<int> v(n+1, 1);
        for (int i = 3; i <= n; ++i) {
            v[i] = max(v[i], 2*v[i-2]);
            v[i] = max(v[i], 2*(i-2));
            if (i > 3) {
                v[i] = max(v[i], 3*v[i-3]);
                v[i] = max(v[i], 3*(i-3));
            }
        }
        return v[n];
    }
};

//1 1 2
