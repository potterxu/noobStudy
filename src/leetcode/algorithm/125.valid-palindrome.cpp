/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (35.33%)
 * Likes:    1158
 * Dislikes: 2837
 * Total Accepted:    571.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValidElement(char c) {
        if (c >= '0' && c <='9') {
            return true;
        } else if (c >= 'a' && c <= 'z') {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int start = 0;
        int end = s.size() - 1;
        bool rv = true;
        while (start < end) {
            char a = tolower(s[start]);
            char b = tolower(s[end]);
            if (!isValidElement(a)) {
                ++start;
                continue;
            }
            if (!isValidElement(b)) {
                --end;
                continue;
            }
            if (a != b) {
                return false;
            }
            ++start;
            --end;
        }
        return rv;
    }
};
// @lc code=end
