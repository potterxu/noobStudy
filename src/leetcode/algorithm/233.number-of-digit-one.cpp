/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (31.14%)
 * Likes:    290
 * Dislikes: 623
 * Total Accepted:    49K
 * Total Submissions: 156.2K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 * 
 * Example:
 * 
 * 
 * Input: 13
 * Output: 6 
 * Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 * 
 * 
 */

class Solution {
public:
    // 0-9 1
    // 0-99 20
    // 0-999 300
    int countDigitOne(int n) {
        if (n <= 0) {
            return 0;
        }
        int dividor = 1;
        int length = 1;
        while (n / 10 >= dividor) {
            dividor *= 10;
            ++length;
        }
        int rv = 0;
        while (n != 0) {
            int digit = n / dividor;
            if (digit > 0) {
                rv += digit * (length-1) * (dividor / 10);
                if (digit > 1) {
                    rv += dividor;
                } else {
                    rv += n % dividor + 1;
                }
            }
            n %= dividor;
            length--;
            dividor /= 10;
        }
        return rv;
    }
};
