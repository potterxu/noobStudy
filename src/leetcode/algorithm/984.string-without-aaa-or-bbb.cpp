/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 *
 * https://leetcode.com/problems/string-without-aaa-or-bbb/description/
 *
 * algorithms
 * Medium (36.75%)
 * Likes:    208
 * Dislikes: 241
 * Total Accepted:    17.8K
 * Total Submissions: 47.4K
 * Testcase Example:  '1\n2'
 *
 * Given two integers A and B, return any string S such that:
 * 
 * 
 * S has length A + B and contains exactly A 'a' letters, and exactly B 'b'
 * letters;
 * The substring 'aaa' does not occur in S;
 * The substring 'bbb' does not occur in S.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = 1, B = 2
 * Output: "abb"
 * Explanation: "abb", "bab" and "bba" are all correct answers.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = 4, B = 1
 * Output: "aabaa"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A <= 100
 * 0 <= B <= 100
 * It is guaranteed such an S exists for the given A and B.
 * 
 * 
 */

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        // if A > B 2(B-b) + b = A, so b "ab" and (B-b) "aab" and vice versa for B > A
        string a = "a";
        string b = "b";
        if (A < B) {
            swap(A, B);
            a = "b";
            b = "a";
        }
        string rv = "";
        int p1n = min(A-B, B);
        p1n = min(p1n, A/2);
        for (int i = 0; i < p1n; ++i) {
            rv += a + a + b;
        }
        A -= 2 * p1n;
        B -= p1n;
        while (A > 0 || B > 0) {
            if (A > 0) {
                --A;
                rv += a;
            }
            if (B > 0) {
                --B;
                rv += b;
            }
        }
        return rv;
    }
};
