/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 *
 * https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (28.61%)
 * Likes:    329
 * Dislikes: 56
 * Total Accepted:    12.9K
 * Total Submissions: 44.3K
 * Testcase Example:  '13\n2'
 *
 * Given integers n and k, find the lexicographically k-th smallest integer in
 * the range from 1 to n.
 * 
 * Note: 1 ≤ k ≤ n ≤ 10^9.
 * 
 * Example:
 * 
 * Input:
 * n: 13   k: 2
 * 
 * Output:
 * 10
 * 
 * Explanation:
 * The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so
 * the second smallest number is 10.
 * 
 * 
 * 
 */

class Solution {
public:
    int nodeNums(long n, long start, long end) {
        int cnt = 0;
        while (start <= n) {
            cnt += min(n+1, end) - start;
            start *= 10;
            end *= 10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        // treat it as a 10-children tree
        int cur = 1;
        while (k > 1) {
            int curNums = nodeNums(n, cur, cur+1);
            if (k > curNums) {
                k -= curNums;
                cur++;
            } else {
                k--;
                cur *= 10;
            }
        }
        return cur;
    }
};
