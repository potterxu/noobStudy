/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.17%)
 * Likes:    7549
 * Dislikes: 561
 * Total Accepted:    995.1K
 * Total Submissions: 3.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

class Solution {
public:
    string preProcess(string &s) {
        string rv = "$#";
        for (char c : s) {
            rv.push_back(c);
            rv.push_back('#');
        }
        rv.push_back('^');
        return rv;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int length = 1;
        string str = preProcess(s);
        vector<int> r(str.size(), 0);
        int cur = 2;
        int center = 2;
        while (cur < str.size()) {
            if (cur > center + r[center]) {
                // exceed the center+radius, so reset center
                center = cur;
            } else {
                int cur_mirror = center - cur + center;
                r[cur] = r[cur_mirror];
                if (cur + r[cur] >= str.size()) {
                    // exceed max length of string
                    r[cur] = str.size() - 1 - cur;
                }
                if (cur + r[cur] >= center + r[center]) {
                    // right boundary exceed center+radius
                    r[cur] = center + r[center] - cur;
                    center = cur;
                }
            }
            if (cur == center) {
                while (str[cur + r[cur] + 1] == str[cur - r[cur] - 1]) {
                    r[cur]++;
                }
            }
            if (r[cur] > length) {
                start = (cur-r[cur]-1)/2;
                length = r[cur];
            }
            ++cur;
        } 
        return s.substr(start, length);
    }
};
