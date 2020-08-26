/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.72%)
 * Likes:    4678
 * Dislikes: 311
 * Total Accepted:    637.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 * 
 * Constraints:
 * 
 * 
 * intervals[i][0] <= intervals[i][1]
 * 
 * 
 */

class Solution {
public:
    struct cmp {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            // put event with earlier start and later end at front
            if (a[0] < b[0]) {
                return true;
            } else if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return false;
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp());
        vector<vector<int>> rv;
        vector<int> cur = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > cur[1]) {
                // cur 不和intervals[i] 重叠
                rv.push_back(cur);
                cur = intervals[i];
            } else {
                cur[1] = max(cur[1], intervals[i][1]);
            }
        }
        rv.push_back(cur);
        return rv;
    }
};
