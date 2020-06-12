/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (34.12%)
 * Likes:    4252
 * Dislikes: 301
 * Total Accepted:    384.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void check(int start, int end, int &rvStart, int &rvEnd) {
        if (rvStart == -1) {
            rvStart = start;
            rvEnd = end;
        } else {
            if (end - start < rvEnd - rvStart) {
                rvStart = start;
                rvEnd = end;
            }
        }
    }
    string minWindow(string s, string t) {
        //printf("%d\n", s.size());
        unordered_map<char, int> charCount;
        int totalCount = 0;
        for (char c : t) {
            charCount[c]++;
            totalCount++;
        }
        if (totalCount == 0 || s.size() < totalCount) {
            return "";
        }
        int start = 0;
        int end = -1;
        int rvStart = -1;
        int rvEnd = -1;
        unordered_map<char, int> m;
        int count = 0;
        while (start <= s.size() - totalCount)  {
            //printf("%d ,%d\n", start, end);
            if (charCount[s[start]] == 0) {
                ++start;
                continue;
            }
            if (end == -1) {
                m[s[start]] = 1;
                count = 1;
                end = start + 1;
            }
            while (end < s.size()) {
                if (count == totalCount) {
                    check(start, end, rvStart, rvEnd);
                    break;
                }
                if (charCount[s[end]] == 0) {
                    ++end;
                    continue;
                }
                m[s[end]]++;
                if (m[s[end]] <= charCount[s[end]]) {
                    count++;
                }
                end++;
            }
            //printf("%d, %d, %d, %d\n", start, end, count, totalCount);
            if (count == totalCount) {
                check(start, end, rvStart, rvEnd);
            }
            if (end == s.size()) {
                if (m[s[start] <= charCount[s[start]]]) {
                    break;
                }
            }
            m[s[start]]--;
            if (m[s[start]] < charCount[s[start]]) {
                count--;
            }
            ++start;
        }
        if (rvStart != -1) {
            return s.substr(rvStart, rvEnd-rvStart);
        }
        return "";
    }
};
// @lc code=end
