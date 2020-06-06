/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (44.54%)
 * Likes:    3074
 * Dislikes: 170
 * Total Accepted:    290.3K
 * Total Submissions: 651.4K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        unordered_map<int,int> startFromToNums;
        for (int num : nums) {
            startFromToNums[num] = 1;
        }
        int rv = 0;
        for (auto &p : startFromToNums) {
            auto it = startFromToNums.find(p.first + p.second);
            while (it != startFromToNums.end()) {
                if (it == startFromToNums.end()) {
                    continue;
                }
                p.second += it->second;
                startFromToNums.erase(it);
                it = startFromToNums.find(p.first + p.second);
            }
            rv = max(rv, p.second);
        }
        return rv;
    }
};
// @lc code=end
