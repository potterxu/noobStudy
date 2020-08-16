/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (30.06%)
 * Likes:    10047
 * Dislikes: 591
 * Total Accepted:    1.6M
 * Total Submissions: 5.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        unordered_map<char, int> m;// m[c] last position of char c
        int preMaxLength = 1;
        m[s[0]] = 0;
        int rv = 1;
        for (int i = 1; i < s.size(); ++i) {
            int l = 0;
            if (m.find(s[i]) == m.end()) {
                l = preMaxLength + 1;
            } else {
                l = min(preMaxLength + 1, i - m[s[i]]);
            }
            m[s[i]] = i;
            rv = max(l, rv);
            preMaxLength = l;
        }
        return rv;
    }
};
