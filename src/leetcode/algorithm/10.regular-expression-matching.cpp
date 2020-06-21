/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (26.54%)
 * Likes:    4111
 * Dislikes: 691
 * Total Accepted:    426K
 * Total Submissions: 1.6M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool equal(char cS, char cP) {
        if (cP == '.') {
            return true;
        }
        return cS == cP;
    }
    bool isMatch(string s, string p) {
        // f(pi, si) is if the p[0:pi+1] can match s[0:si+1]
        // f(pi, si) = 
        // p[pi+1] == '*' ? 
        // (f(pi-1, si) || (s[si] == p[pi] && (f(pi-1, si-1) || f(pi, si-1))))
        // : s[si] == p[pi] && f(pi-1 , si-1)
        unordered_map<int, unordered_map<int, bool>> f; //f[pi][si] = true means f(pi, si) = true
        int pi = 0;
        f[-1][-1] = true; // empty s matchs empty p
        while(pi < p.size()) {
            if (pi < p.size() - 1 && p[pi+1] == '*') {
                if (f.find(pi-1) != f.end()) {
                    f[pi+1][-1] = f[pi-1][-1];
                    for (size_t si = 0; si < s.size(); ++si) {
                        f[pi+1][si] = f[pi-1][si];
                        if (equal(s[si], p[pi])) {
                            f[pi+1][si] = f[pi+1][si] || f[pi-1][si-1] || f[pi+1][si-1];
                        }
                    }
                }
                pi += 2;
            } else {
                for (auto &pair : f[pi-1]) {
                    if (pair.first + 1 < s.size()) {
                        f[pi][pair.first+1] = equal(s[pair.first+1], p[pi]) && pair.second;
                    }
                }
                pi += 1;
            }
        }
        return f[p.size()-1][s.size()-1];
    }
};
// @lc code=end
