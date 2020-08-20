/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (61.75%)
 * Likes:    2076
 * Dislikes: 82
 * Total Accepted:    163.1K
 * Total Submissions: 259.7K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Find the maximum area of an island in the given 2D array. (If there is no
 * island, the maximum area is 0.)
 * 
 * Example 1:
 * 
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * Given the above grid, return 6. Note the answer is not 11, because the
 * island must be connected 4-directionally.
 * 
 * Example 2:
 * 
 * 
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * 
 * Note: The length of each dimension in the given grid does not exceed 50.
 * 
 */

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &area) {
        if (i < 0 || i >= grid.size()) {
            return;
        }
        if (j < 0 || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] != 1) {
            return;
        }
        grid[i][j] = -1; // visited;
        area += 1;
        for (int diff = -1; diff <= 1; ++diff) {
            if (diff == 0) {
                continue;
            }
            dfs(grid, i+diff, j, area);
            dfs(grid, i, j+diff, area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int area = 0;
                dfs(grid, i, j, area);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};