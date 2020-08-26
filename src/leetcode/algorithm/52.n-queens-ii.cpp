/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (56.81%)
 * Likes:    557
 * Dislikes: 159
 * Total Accepted:    137.5K
 * Total Submissions: 237.2K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

class Solution {
public:
    vector<bool> usedR; // r = constant [0, n-1]
    vector<bool> usedC; // c = constant [0, n-1]
    vector<bool> usedDia1; // r+c = constant [0, 2n-2]
    vector<bool> usedDia2; // r-c = contsant [-n+1, n-1] so introducing r-c+(n-1) = [0, 2n-2]

    void process(int n, int r, int c, vector<string> &cur, int &rv) {
        if (usedC[c] || usedR[r] || usedDia1[r+c] || usedDia2[r-c+cur.size()-1]) {
            // cannot put queen
            return;
        }
        cur[r][c] = 'Q';
        if (n == 1) {
            rv++;
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
    int totalNQueens(int n) {
        int rv = 0;
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
