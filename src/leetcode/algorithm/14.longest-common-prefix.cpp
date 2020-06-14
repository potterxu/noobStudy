/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.11%)
 * Likes:    2447
 * Dislikes: 1822
 * Total Accepted:    734.5K
 * Total Submissions: 2.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

// @lc code=start
class Solution {
public:
    int findPrefixEnd(string &s1, string &s2, int preEnd) {
        int rv = -1;
        int ptr = 0;
        while (ptr < s1.size() && ptr < s2.size() && ptr <= preEnd) {
            if (s1[ptr] != s2[ptr]) {
                break;
            }
            rv = ptr;
            ++ptr;
        }
        return min(rv, preEnd);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        string prefix = strs[0];
        int prefixEnd = prefix.size() - 1;;
        for (int i = 1; i < strs.size(); ++i) {
            prefixEnd = findPrefixEnd(prefix, strs[i], prefixEnd);
            if (prefixEnd == -1) {
                return "";
            }
        }
        return prefix.substr(0, prefixEnd + 1);
    }
};
// @lc code=end
