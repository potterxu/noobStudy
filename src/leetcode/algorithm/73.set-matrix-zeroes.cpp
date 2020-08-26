/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (42.63%)
 * Likes:    2383
 * Dislikes: 320
 * Total Accepted:    336.3K
 * Total Submissions: 777.3K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given an m x n matrix. If an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -10^9 <= matrix[i][j] <= 10^9
 * 
 * 
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        bool firstRowSetZero = false;
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        firstRowSetZero = true; // row 0 set zero
                    } else {
                        matrix[i][0] = 0; // row i set zero
                    }
                    matrix[0][j] = 0; // col j set zero
                }
            }
        }
        for (size_t i = matrix.size()-1; i > 0; --i) {
            if (matrix[i][0] == 0) {
                for (size_t j = 1; j < matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = matrix[0].size()-1; j >= 0; --j) {
            if (matrix[0][j] == 0) {
                for (size_t i = 1; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowSetZero) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};
