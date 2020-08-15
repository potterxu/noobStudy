/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 *
 * https://leetcode.com/problems/remove-covered-intervals/description/
 *
 * algorithms
 * Medium (59.88%)
 * Likes:    182
 * Dislikes: 13
 * Total Accepted:    11.1K
 * Total Submissions: 19.2K
 * Testcase Example:  '[[1,4],[3,6],[2,8]]'
 *
 * Given a list of intervals, remove all intervals that are covered by another
 * interval in the list. Interval [a,b) is covered by interval [c,d) if and
 * only if c <= a and b <= d.
 * 
 * After doing so, return the number of remaining intervals.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,4],[3,6],[2,8]]
 * Output: 2
 * Explanation: Interval [3,6] is covered by [2,8], therefore it is
 * removed.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 1000
 * 0 <= intervals[i][0] < intervals[i][1] <= 10^5
 * intervals[i] != intervals[j] for all i != j
 * 
 * 
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto less = [&](vector<int> &a, vector<int> &b) {
            if (a[0] < b[0]) {
                return true;
            }
            if (a[0] == b[0]) {
                return a[1] >= b[1];
            }
            return false;
        };
        sort(intervals.begin(), intervals.end(), less);
        int cnt = 0;
        int i = 0;
        int j = 1;
        while (j < intervals.size()) {
            if (intervals[j][1] <= intervals[i][1]) {
                ++cnt;
            } else {
                i = j;
            }
            ++j;
        }
        return intervals.size() - cnt;
    }
};
