/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 *
 * https://leetcode.com/problems/convert-to-base-2/description/
 *
 * algorithms
 * Medium (58.55%)
 * Likes:    144
 * Dislikes: 155
 * Total Accepted:    10.6K
 * Total Submissions: 18K
 * Testcase Example:  '2'
 *
 * Given a number N, return a string consisting of "0"s and "1"s that
 * represents its value in base -2 (negative two).
 * 
 * The returned string must have no leading zeroes, unless the string is
 * "0".
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: "110"
 * Explantion: (-2) ^ 2 + (-2) ^ 1 = 2
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: "111"
 * Explantion: (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 4
 * Output: "100"
 * Explantion: (-2) ^ 2 = 4
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= N <= 10^9
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) {
            return "0";
        }
        string rv = "";
        while (N != 0) {
            int remain = N % -2;
            N /= -2;
            if (remain == -1) {
                remain += 2;
                N += 1;
            }
            if (remain) {
                rv = "1" + rv;
            } else if (N != 0) {
                rv = "0" + rv;
            }
        }
        return rv;
    }
};


// @lc code=end
