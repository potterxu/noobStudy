/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (62.17%)
 * Likes:    4187
 * Dislikes: 108
 * Total Accepted:    637.3K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

class Solution {
public:
    void permute(vector<int>& nums, vector<bool> &used, vector<vector<int>> &rv, vector<int> &cur) {
        if (cur.size() == nums.size()) {
            rv.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            cur.push_back(nums[i]);
            permute(nums, used, rv, cur);
            cur.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> rv;
        vector<int> cur;
        permute(nums, used, rv, cur);
        return rv;
    }
};