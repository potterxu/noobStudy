/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 *
 * https://leetcode.com/problems/remove-boxes/description/
 *
 * algorithms
 * Hard (41.75%)
 * Likes:    655
 * Dislikes: 50
 * Total Accepted:    15.4K
 * Total Submissions: 36K
 * Testcase Example:  '[1,3,2,2,2,3,4,3,1]\r'
 *
 * Given several boxes with different colors represented by different positive
 * numbers.
 * You may experience several rounds to remove boxes until there is no box
 * left. Each time you can choose some continuous boxes with the same color
 * (composed of k boxes, k >= 1), remove them and get k*k points.
 * Find the maximum points you can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: boxes = [1,3,2,2,2,3,4,3,1]
 * Output: 23
 * Explanation:
 * [1, 3, 2, 2, 2, 3, 4, 3, 1] 
 * ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
 * ----> [1, 3, 3, 3, 1] (1*1=1 points) 
 * ----> [1, 1] (3*3=9 points) 
 * ----> [] (2*2=4 points)
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= boxes.length <= 100
 * 1 <= boxes[i] <= 100
 * 
 * 
 */

class Solution {
public:
    int removeBoxes(vector<int> &boxes, int l, int r, int k, vector<vector<vector<int>>> &dp) {
        if (r < l) {
            return 0;
        }
        if (dp[l][r][k] != 0) {
            return dp[l][r][k];
        }
        dp[l][r][k] = removeBoxes(boxes, l, r-1, 0, dp) + (k+1) * (k+1);
        for (int i = l; i < r; ++i) {
            if (boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k], removeBoxes(boxes, l, i, k+1, dp) + removeBoxes(boxes, i+1, r-1, 0, dp));
            }
        }
        return dp[l][r][k];
    }
    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int>>> dp(boxes.size(), vector<vector<int>>(boxes.size(), vector<int>(boxes.size(),0)));
        return removeBoxes(boxes, 0, boxes.size()-1, 0, dp);

    }
};
