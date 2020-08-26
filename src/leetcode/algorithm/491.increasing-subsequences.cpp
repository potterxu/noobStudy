/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 *
 * https://leetcode.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (45.16%)
 * Likes:    757
 * Dislikes: 118
 * Total Accepted:    48.9K
 * Total Submissions: 105.7K
 * Testcase Example:  '[4,6,7,7]'
 *
 * Given an integer array, your task is to find all the different possible
 * increasing subsequences of the given array, and the length of an increasing
 * subsequence should be at least 2.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also
 * be considered as a special case of increasing sequence.
 * 
 * 
 */

class Solution {
public:
    void dfs(int curI, int lastNum, vector<int>& nums, vector<vector<int>> &rv, vector<int> &cur) {
        if (curI == nums.size()) {
            if (cur.size() > 1) {
                rv.push_back(cur);
            }
           return;
       }
       // choose curI
       if (nums[curI] >= lastNum) {
           cur.push_back(nums[curI]);
           dfs(curI+1, nums[curI], nums, rv, cur);
           cur.pop_back();
       }

       // not choose curI
       // if equal to lastNum, then cannot unchoose this num to reduce duplicates
       if (nums[curI] != lastNum) {
           dfs(curI+1, lastNum, nums, rv, cur);
       }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> rv;
        vector<int> cur;
        dfs(0, -101, nums, rv, cur);
        return rv;
    }
};
