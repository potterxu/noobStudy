/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 *
 * https://leetcode.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (27.51%)
 * Likes:    502
 * Dislikes: 351
 * Total Accepted:    43.6K
 * Total Submissions: 158.5K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * Given two strings A and B of lowercase letters, return true if and only if
 * we can swap two letters in A so that the result equals B.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: A = "ab", B = "ba"
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = "ab", B = "ab"
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = "aa", B = "aa"
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: A = "", B = "aa"
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A and B consist only of lowercase letters.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        if (A.size() < 2) {
            return false;
        }
        int sum = 0; // must be equal to 0 at last
        int diffNum = 0; // must be equal to 2 or 0
        bool hasRedundant = false; // check has redundant char
        unsigned int exist = 0;
        for (int i = 0; i < A.size(); ++i) {
            int diff = A[i] - B[i];
            if (diff != 0) {
                sum += diff;
                diffNum++;
                if (diffNum > 2) {
                    return false;
                }
            }
            if (!hasRedundant) {
                int flag = 1 << (A[i] - 'a');
                if (exist & flag) {
                    hasRedundant = true;
                }
                exist |= flag;
            }
        }
        if (sum == 0) {
            if (diffNum == 2) {
                return true;
            }
            if (diffNum ==0 && hasRedundant) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
