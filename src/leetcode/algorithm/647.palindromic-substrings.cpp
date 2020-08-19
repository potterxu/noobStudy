/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (60.00%)
 * Likes:    2843
 * Dislikes: 116
 * Total Accepted:    196.5K
 * Total Submissions: 323.5K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */

class Solution {
public:
    int bfs(string s, int i) {
        int rv = 1;
        for (int r = 1; i-r >= 0 && i+r < s.size(); ++r) {
            if (s[i-r] == s[i+r]) {
                ++rv;
            } else {
                break;
            }
        }
        if (i+1 < s.size() && s[i] == s[i+1]) {
            ++rv;
            for (int r = 1; i-r >= 0 && i+1+r < s.size(); ++r) {
                if (s[i-r] == s[i+r+1]) {
                    ++rv;
                } else {
                    break;
                }
            }
        }
        return rv;
    }

    int bfs(string s) {
        if (s.size() < 2) {
            return s.size();
        }
        int rv = 0;
        for (int i = 0; i < s.size(); ++i) {
            rv += bfs(s, i);
        }
        return rv;
    }

    string preProcess(string s) {
        string rv = "$#";
        for (char c : s) {
            rv.push_back(c);
            rv.push_back('#');
        }
        rv.push_back('^');
        return rv;
    }

    int manacher(string &s) {
        if (s.size() < 2) {
            return s.size();
        }
        string str = preProcess(s);
        vector<int> r(str.size(), 0);
        int cur = 2;
        int center = cur;
        while (cur < str.size()) {
            if (cur > center) {
                if (cur >= center + r[center]) {
                    // 超出了center的回文界限 重置center
                    center = cur;
                } else {
                    int mirror = center - cur + center;
                    r[cur] = r[mirror];
                    if (cur + r[cur] >= str.size()-1){
                        // 超出了字符串长度界限
                        r[cur] = str.size()-2-cur;
                    }
                    if (cur + r[cur] >= center + r[center]) {
                        // 超出了center 回文界限， 重置center
                        r[cur] = center + r[center] - cur;
                        center = cur;
                    }
                }
            }
            if (cur == center) {
                // 中心扩散计算最大字符串
                int newR = r[cur];
                while (true) {
                    if (str[cur-newR-1] != str[cur+newR+1]) {
                        break;
                    }
                    ++newR;
                }
                r[cur] = newR;
            }
            ++cur;
        }
        int rv = 0;
        for (int i = 0; i < str.size(); ++i) {
            //printf("%d, ", r[i]);
            rv += (r[i]+1)/2;
        } 
        return rv;
    }

    int countSubstrings(string s) {
        return manacher(s);
        //return bfs(s);
    }
};
