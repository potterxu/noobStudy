/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (26.31%)
 * Likes:    1915
 * Dislikes: 677
 * Total Accepted:    247.3K
 * Total Submissions: 879.8K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= board.size()) {
            return;
        }
        if (y < 0 || y >= board[0].size()) {
            return;
        }
        // 'O', 'X' means non-visited, 0 means should be 'O' after visit
        if (board[x][y] == 0) {
            //visited
            return;
        }
        if (board[x][y] == 'X') {
            return;
        }
        board[x][y] = 0;
        dfs(board, x+1, y);
        dfs(board, x-1, y);
        dfs(board, x, y+1);
        dfs(board, x, y-1);
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        // find all 'O' in the boreder and do dfs
        int i = 0;
        while (i < board.size() || i < board[0].size()) {
            if (i < board.size()) {
                dfs(board, i, 0);
                dfs(board, i, board[0].size()-1);
            }
            if (i < board[0].size()) {
                dfs(board, 0, i);
                dfs(board, board.size()-1, i);
            }
            ++i;
        }
        for (auto &v : board) {
            for (auto &n : v) {
                if (n == 0) {
                    n = 'O';
                } else {
                    n = 'X';
                }
            }
        }
    }
};