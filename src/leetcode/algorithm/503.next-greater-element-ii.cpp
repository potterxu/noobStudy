/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (55.39%)
 * Likes:    1559
 * Dislikes: 73
 * Total Accepted:    98.4K
 * Total Submissions: 174.3K
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s; // stack of index
        vector<int> rv(nums.size(), -1);
        int loopCnt = nums.size() + nums.size() - 1;
        for (int i = 0; i < loopCnt; ++i) {
            int index = i;
            if (index >= nums.size()) {
                index -= nums.size();
            }
            while (!s.empty()) {
                if (nums[s.top()] >= nums[index]) {
                    break;
                }
                rv[s.top()] = nums[index];
                s.pop();
            }
            if (rv[index] == -1) {
                s.push(index);
            }
        }
        return rv;
    }
};
