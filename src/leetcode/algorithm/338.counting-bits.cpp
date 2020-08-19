/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (68.99%)
 * Likes:    2872
 * Dislikes: 175
 * Total Accepted:    297.1K
 * Total Submissions: 427K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,1]
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: [0,1,1,2,1,2]
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 * 
 */

class Solution {
public:
    // for (n+1) bits, the highest bit is always 1 and the remaining n bits is changing with the same order as previous ( n) bits number
    // array[2^0 - 1] = {0}
    // array[2^1 - 1] = {0, 1}
    // array[2^2 - 1] = {0, 1, 0+1, 1+1}
    // array[2^3 - 1] = {0, 1, 0+1, 1+1, 0+1, 1+1, 0+1+1, 1+1+1}
    vector<int> countBits(int num) {
        vector<int> rv(num+1, 0);
        int loopStart = 1;
        for (int i = 1; i <= num; ++i) {
            if (i - loopStart >= loopStart) {
                loopStart *= 2;
            }
            rv[i] = rv[i-loopStart] + 1;
        }
        return rv;
    }
};
