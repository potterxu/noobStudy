/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 *
 * https://leetcode.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (58.25%)
 * Likes:    628
 * Dislikes: 528
 * Total Accepted:    64.2K
 * Total Submissions: 108.5K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n[3,0]'
 *
 * Let's play the minesweeper game (Wikipedia, online game)!
 * 
 * You are given a 2D char matrix representing the game board. 'M' represents
 * an unrevealed mine, 'E' represents an unrevealed empty square, 'B'
 * represents a revealed blank square that has no adjacent (above, below, left,
 * right, and all 4 diagonals) mines, digit ('1' to '8') represents how many
 * mines are adjacent to this revealed square, and finally 'X' represents a
 * revealed mine.
 * 
 * Now given the next click position (row and column indices) among all the
 * unrevealed squares ('M' or 'E'), return the board after revealing this
 * position according to the following rules:
 * 
 * 
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it
 * to revealed blank ('B') and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent
 * mines.
 * Return the board when no more squares will be revealed.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The range of the input matrix's height and width is [1,50].
 * The click position will only be an unrevealed square ('M' or 'E'), which
 * also means the input board contains at least one clickable square.
 * The input board won't be a stage when game is over (some mines have been
 * revealed).
 * For simplicity, not mentioned rules should be ignored in this problem. For
 * example, you don't need to reveal all the unrevealed mines when the game is
 * over, consider any cases that you will win the game or flag any squares.
 * 
 * 
 */

class Solution {
public:
    int getMineCnt(vector<vector<char>>& board, int r, int c) {
        int mineCnt = 0;
        for (int i = r-1; i <= r+1; ++i) {
            for (int j = c-1; j <= c+1; ++j) {
                if (i < 0 || i >= board.size()
                    || j < 0 || j >= board[0].size()
                ) {
                    continue;
                }
                if (i == r && j == c) {
                    continue;
                }
                if (board[i][j] == 'M') {
                    ++mineCnt;
                }
            }
        }
        return mineCnt;
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
            return;
        }
        if (board[r][c] != 'E') {
            return;
        }
        int mineCnt = getMineCnt(board, r, c);
        if (mineCnt == 0) {
            board[r][c] = 'B';
        } else {
            board[r][c] = mineCnt + '0';
            return;
        }
        for (int i = r-1; i <= r+1; ++i) {
            for (int j = c-1; j <= c+1; ++j) {
                if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
                    continue;
                }
                if (i == r && j == c) {
                    continue;
                }
                dfs(board, i, j);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];
        if (r < 0 || r >= board.size()) {
            return board;
        }
        if (c < 0 || c >= board[0].size()) {
            return board;
        }
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
        }
        dfs(board, r, c);
        return board;
    }
};
