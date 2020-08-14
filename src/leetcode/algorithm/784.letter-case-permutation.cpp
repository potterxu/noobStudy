/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (63.33%)
 * Likes:    1355
 * Dislikes: 107
 * Total Accepted:    94.5K
 * Total Submissions: 146.2K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 * 
 * 
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 * 
 * Input: S = "12345"
 * Output: ["12345"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * S will be a string with length between 1 and 12.
 * S will consist only of letters or digits.
 * 
 * 
 */

class Solution {
public:
    bool isLetter(char c) {
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
        return false; 
    }
    char invertLetter(char c) {
        if (c >= 'a' && c <= 'z') {
            return c - 0x20;
        } else if (c >= 'A' && c <= 'Z') {
            return c + 0x20;
        }
        return 0;
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> rv;
        rv.push_back(S);
        for (int i = 0; i < S.size(); ++i) {
            if (isLetter(S[i])) {
                char invert = invertLetter(S[i]);
                size_t size = rv.size();
                for (int j = 0; j < size; ++j) {
                    rv.push_back(rv[j]);
                    rv.back()[i] = invert;
                }
            }
        }
        return rv;
    }
};
