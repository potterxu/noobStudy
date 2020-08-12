/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (33.36%)
 * Likes:    1802
 * Dislikes: 815
 * Total Accepted:    302.7K
 * Total Submissions: 893.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == ""
            || num1 == "0"
            || num2 == ""
            || num2 == "0")
        {
            return "0";
        }
        string rv = "";
        int carry = 0;
        for (int pos = 0; pos <= num1.size() + num2.size() - 2; ++pos) {
            int sum = carry;
            for (int i = 0; i <= pos; ++i) {
                if (i >= num1.size()) {
                    break;
                }
                int j = pos - i;
                if (j >= num2.size()) {
                    continue;
                }
                sum += (num1[num1.size()-1-i] - '0') * (num2[num2.size()-1-j]-'0');
            }
            rv.push_back(sum%10+'0');
            carry = sum / 10;
        }
        if (carry > 0) {
            rv.push_back(carry + '0');
        }
        reverse(rv.begin(), rv.end());
        return rv;
    }
};