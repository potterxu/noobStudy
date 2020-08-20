/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (61.47%)
 * Likes:    5618
 * Dislikes: 281
 * Total Accepted:    579.7K
 * Total Submissions: 922.3K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // from begin to i, k represent k extra ( in prefix, if ( > 0. then ）can also put at i+1 
        vector<int> extraNumber;
        vector<string> rv;
        if (n < 1) {
            return rv;
        }
        extraNumber.push_back(1);
        rv.push_back("(");
        for (int num = 1; num < 2*n; ++num) {
            size_t size = rv.size();
            for (int i = 0; i < size; ++i) {
                if (extraNumber[i] == 0) {
                    // must put ( here because no extra at prefix
                    rv[i].push_back('(');
                    extraNumber[i]++;
                } else if (extraNumber[i] == 2*n-num) {
                    // the remaining should be all )
                    rv[i].push_back(')');
                    extraNumber[i]--;
                } else {
                    // have two choices
                    rv.push_back(rv[i]+'(');
                    extraNumber.push_back(extraNumber[i]+1);
                    rv[i].push_back(')');
                    extraNumber[i]--;
                }
            }
        }
        return rv;
    }
};
