/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (35.65%)
 * Likes:    1774
 * Dislikes: 4785
 * Total Accepted:    476.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || s.size() <= numRows || numRows == 1) {
            return s;
        }
        string rv = "";
        // row 0 ~ n-1
        // for row k, the sequece is occurring as pair
        // (s[0 * (n-1) - k], s[0 * (n-1) + k])
        // (s[2 * (n-1) - k], s[2 * (n-1) + k])
        // ...
        for (int k = 0; k < numRows; ++k) {
            int i = -k;
            int j = k;
            while (i < s.size() || j < s.size()) {
                if (i >= 0) {
                    rv.push_back(s[i]);
                }
                if (k != 0 && k != numRows -1 && j < s.size()) {
                    rv.push_back(s[j]);
                }
                i += 2*(numRows-1);
                j += 2*(numRows-1);
            }
        }
        return rv;
    }
};
