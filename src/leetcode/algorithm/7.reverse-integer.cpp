/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.71%)
 * Likes:    3580
 * Dislikes: 5621
 * Total Accepted:    1.2M
 * Total Submissions: 4.6M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        int rv = 0;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        while (x > 0) {
            if (INT_MAX / 10 < rv) {
                // overflow
                return 0;
            }
            rv *= 10;
            rv += x % 10;
            x /= 10;
        }
        return rv * sign;
    }
};
