/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 *
 * https://leetcode.com/problems/decode-ways-ii/description/
 *
 * algorithms
 * Hard (26.23%)
 * Likes:    429
 * Dislikes: 516
 * Total Accepted:    31.8K
 * Total Submissions: 119.6K
 * Testcase Example:  '"*"'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping way:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Beyond that, now the encoded string can also contain the character '*',
 * which can be treated as one of the numbers from 1 to 9.
 * 
 * 
 * 
 * 
 * Given the encoded message containing digits and the character '*', return
 * the total number of ways to decode it.
 * 
 * 
 * 
 * Also, since the answer may be very large, you should return the output mod
 * 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * Input: "*"
 * Output: 9
 * Explanation: The encoded message can be decoded to the string: "A", "B",
 * "C", "D", "E", "F", "G", "H", "I".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1*"
 * Output: 9 + 9 = 18
 * 
 * 
 * 
 * Note:
 * 
 * The length of the input string will fit in range [1, 10^5].
 * The input string will only contain the character '*' and digits '0' - '9'.
 * 
 * 
 */

class Solution {
public:
    int canForm(char a) {
        if (a == '*') {
            return 9;
        } else if (a == '0') {
            return 0;
        }
        return 1;
    }
    int canForm(char a, char b) {
        if (a == '1') {
            if (b == '*') {
                return 9;
            }
            return 1;
        } else if (a == '2') {
            if (b >= '7' && b <= '9') {
                return 0;
            } else if (b == '*') {
                return 6;
            }
            return 1;
        } else if (a == '*') {
            return canForm('1', b) + canForm('2', b);
        }
        return 0;
    }
    int numDecodings(string s) {
        int d = 1000000007;
        int pre2 = canForm(s[0]);
        if (s.size() == 1) {
            return pre2;
        }
        int pre1 = canForm(s[1]) * pre2 + canForm(s[0], s[1]);
        for (int i = 2; i < s.size(); ++i) {
            int num = 0;
            num += canForm(s[i]) * pre1;
            num %= d;
            num += canForm(s[i-1], s[i]) * pre2;
            num %= d;
            pre2 = pre1;
            pre1 = num;
        }
        return pre1;
    }
};
