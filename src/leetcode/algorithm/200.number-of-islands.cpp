/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (46.10%)
 * Likes:    5997
 * Dislikes: 202
 * Total Accepted:    769.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 * 
 * 
 */

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i , int j) {
        if (i < 0 || i >= grid.size()) {
            return;
        }
        if (j < 0 || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] == '0' || grid[i][j] == -1) {
            return;
        }

        grid[i][j] = -1;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rv = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++rv;
                    dfs(grid, i, j);
                }
            }
        }
        return rv;
    }
};
