/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (30.88%)
 * Likes:    1421
 * Dislikes: 85
 * Total Accepted:    153.5K
 * Total Submissions: 490.5K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 */

class Solution {
public:
    // f(i, j) = (f(i-1, j) && s1[i] == s3[i+j]) || (f(i, j-1) && s2[j] == s3[i+j])
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() != s3.size() - s2.size()) {
            return false;
        }
        if (s1.empty()) {
            return s2 == s3;
        }
        if (s2.empty()) {
            return s1 == s3;
        }
        vector<bool> dp(s2.size() + 1);
        dp[0] = true;
        for (int j = 1; j < s2.size() + 1; ++j) {
            dp[j] = (s3[j-1] == s2[j-1]) && dp[j-1];
        }
        for (int i = 1; i < s1.size() + 1; ++i) {
            dp[0] = dp[0] && (s3[i-1] == s1[i-1]);
            for (int j = 1; j < s2.size() + 1; ++j) {
                dp[j] = dp[j] && (s3[i+j-1] == s1[i-1]);
                dp[j] = dp[j] || (s3[i+j-1] == s2[j-1] && dp[j-1]);
            }
        }
        return dp.back();
    }
};
