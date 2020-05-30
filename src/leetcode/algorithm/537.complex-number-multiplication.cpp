/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 *
 * https://leetcode.com/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (67.03%)
 * Total Accepted:    45.8K
 * Total Submissions: 68.4K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * 
 * Given two strings representing two complex numbers.
 * 
 * 
 * You need to return a string representing their multiplication. Note i^2 = -1
 * according to the definition.
 * 
 * 
 * Example 1:
 * 
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i^2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i^2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 * 
 * 
 * 
 * Note:
 * 
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and
 * b will both belong to the range of [-100, 100]. And the output should be
 * also in this form.
 * 
 * 
 */
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int plus = a.find("+");
        int a1 = stoi(a.substr(0, plus));
        int b1 = stoi(a.substr(plus+1, a.size() - 2 - plus));
        plus = b.find("+");
        int a2 = stoi(b.substr(0, plus));
        int b2 = stoi(b.substr(plus+1, b.size() - 2 - plus));
        string out = "";
        out += to_string(a1*a2 - b1*b2);
        out += "+";
        out += to_string(a1*b2 + a2*b1);
        out += "i";
        return out;
    }
};
