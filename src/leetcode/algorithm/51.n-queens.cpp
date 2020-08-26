/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (45.33%)
 * Likes:    2052
 * Dislikes: 77
 * Total Accepted:    209.6K
 * Total Submissions: 447.8K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */

class Solution {
public:
    vector<bool> usedR; // r = constant [0, n-1]
    vector<bool> usedC; // c = constant [0, n-1]
    vector<bool> usedDia1; // r+c = constant [0, 2n-2]
    vector<bool> usedDia2; // r-c = contsant [-n+1, n-1] so introducing r-c+(n-1) = [0, 2n-2]

    void process(int n, int r, int c, vector<string> &cur, vector<vector<string>> &rv) {
        if (usedC[c] || usedR[r] || usedDia1[r+c] || usedDia2[r-c+cur.size()-1]) {
            // cannot put queen
            return;
        }
        cur[r][c] = 'Q';
        if (n == 1) {
            rv.push_back(cur);
        } else {
            usedC[c] = true;
            usedR[r] = true;
            usedDia1[r+c] = true;
            usedDia2[r-c+cur.size()-1] = true;
            for (int i = r; i < cur.size(); ++i) {
                for (int j = 0; j < cur.size(); ++j) {
                    if (i == r && j <= c) {
                        continue;
                    }
                    process(n-1, i, j, cur, rv);
                }
            }
            usedC[c] = false;
            usedR[r] = false;
            usedDia1[r+c] = false;
            usedDia2[r-c+cur.size()-1] = false;
        }
        cur[r][c] = '.';
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rv;
        usedR = vector<bool>(n, false);
        usedC = vector<bool>(n, false);
        usedDia1 = vector<bool>(n*2-1, false);
        usedDia2 = vector<bool>(n*2-1, false);
        string s = "";
        for (int i = 0; i < n; ++i) {
            s.push_back('.');
        }
        vector<string> cur(n, s);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                process(n, r, c, cur, rv);
            }
        }
        return rv;
    }
};