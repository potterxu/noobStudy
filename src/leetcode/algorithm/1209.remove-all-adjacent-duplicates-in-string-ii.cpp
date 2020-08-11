/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
 *
 * algorithms
 * Medium (56.26%)
 * Likes:    576
 * Dislikes: 14
 * Total Accepted:    34.2K
 * Total Submissions: 60.1K
 * Testcase Example:  '"abcd"\n2'
 *
 * Given a string s, a k duplicate removal consists of choosing k adjacent and
 * equal letters from s and removing them causing the left and the right side
 * of the deleted substring to concatenate together.
 * 
 * We repeatedly make k duplicate removals on s until we no longer can.
 * 
 * Return the final string after all such duplicate removals have been made.
 * 
 * It is guaranteed that the answer is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcd", k = 2
 * Output: "abcd"
 * Explanation: There's nothing to delete.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "deeedbbcccbdaa", k = 3
 * Output: "aa"
 * Explanation: 
 * First delete "eee" and "ccc", get "ddbbbdaa"
 * Then delete "bbb", get "dddaa"
 * Finally delete "ddd", get "aa"
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pbbcggttciiippooaais", k = 2
 * Output: "ps"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 2 <= k <= 10^4
 * s only contains lower case English letters.
 * 
 * 
 */

class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (k > s.size()) {
            return s;
        }
        deque<pair<char,int>> q;
        for (char c : s) {
            if (!q.empty()) {
                if (q.back().first != c) {
                    q.push_back({c, 1});
                } else {
                    q.back().second++;
                    if (q.back().second == k) {
                        q.pop_back();
                    }
                }
            } else {
                q.push_back({c,1});
            }
        }
        string rv = "";
        for (auto &p : q) {
            for (int i = 0; i < p.second; ++i) {
                rv.push_back(p.first);
            }
        }
        return rv;
    }
};
