/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (47.53%)
 * Total Accepted:    192.4K
 * Total Submissions: 392.9K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * Examples:
 * 
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }

    string decodeString(string s) {
        string rv = "";
        stack<string> mem;
        string time = "";
        string str = "";
        int squareC = 0;
        for (char c : s) {
            if (isNumber(c)) {
                if (!str.empty()) {
                    mem.push(str);
                    str = "";
                }
                time.push_back(c);
            } else if (c == '[') {
                mem.push(time);
                time = "";
                squareC++;
            } else if (c == ']') {
                string a = mem.top();
                mem.pop();
                if (isNumber(a[0])) {
                    int t = stoi(a);
                    string tmp = "";
                    for (int i = 0; i < t; ++i) {
                        tmp += str;
                    }
                    str = tmp;
                } else {
                    str = a + str;
                }
                squareC--;
                if (squareC == 0) {
                    while (!mem.empty()) {
                        string a = mem.top();
                        mem.pop();
                        if (isNumber(a[0])) {
                            int t = stoi(a);
                            string tmp = "";
                            for (int i = 0; i < t; ++i) {
                                tmp += str;
                            }
                            str = tmp;
                        } else {
                            str = a + str;
                        }
                    }
                    rv += str;
                    str = "";
                }
            } else {
                str.push_back(c);
            }
            
        }
        return rv + str;
    }
};
