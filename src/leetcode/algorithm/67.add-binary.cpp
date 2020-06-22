/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (43.56%)
 * Likes:    1705
 * Dislikes: 268
 * Total Accepted:    441.6K
 * Total Submissions: 1M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 * 
 * 
 */

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0") {
            return b;
        } else if (b == "0") {
            return a;
        }
        string sum = "";
        char carry = 0;
        int ptr = 0;
        while (ptr < a.size() || ptr < b.size()) {
            char aV = 0;
            char bV = 0;
            if (ptr < a.size()) {
                aV = a[a.size()-1-ptr] - '0';
            }
            if (ptr < b.size()) {
                bV = b[b.size()-1-ptr] - '0';
            }
            char s = aV + bV + carry;
            if (s < 2) {
                sum.push_back(s + '0');
                carry = 0;
            } else {
                carry = 1;
                sum.push_back(s - 2 + '0');
            }
            ++ptr;
        }
        if (carry) {
            sum.push_back('1');
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};