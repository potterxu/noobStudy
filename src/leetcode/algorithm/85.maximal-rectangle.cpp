/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (36.90%)
 * Likes:    3019
 * Dislikes: 71
 * Total Accepted:    185.3K
 * Total Submissions: 489.7K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */

class Solution {
public:
    int maxRecSize(vector<int> &dp) {
        // monotonic stack
        stack<int> s;
        int maxSize = 0;
        int size = dp.size();
        s.push(-1);
        for (int i = 0; i < size; ++i) {
            while (s.size() > 1) {
                if (dp[i] > dp[s.top()]) {
                    break;
                }
                int j = s.top();
                s.pop();
                maxSize = max(maxSize, dp[j] * (i-s.top()-1));
            }
            s.push(i);
        }
        while (s.size() > 1) {
            int j = s.top();
            s.pop();
            maxSize = max(maxSize, dp[j] * (size-s.top()-1));
        }
        return maxSize;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        // count the highest height at each point at each row
        vector<int> dp(matrix[0].size(), 0);
        int maxSize = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0') {
                    dp[j] = 0;
                } else {
                    dp[j] += 1;
                }
                // now get the bar height at each point in this row
                // calculate the max rectangle size with this row as the bottom
            }
            maxSize = max(maxSize, maxRecSize(dp));
        }
        return maxSize;
    }
};
