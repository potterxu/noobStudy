/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (50.24%)
 * Likes:    2778
 * Dislikes: 54
 * Total Accepted:    159.2K
 * Total Submissions: 314.8K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 * 
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3,null,3,null,1]
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * Output: 7 
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,5,1,3,null,1]
 * 
 * 3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void rob(TreeNode* root, int &stealRoot, int &notStealRoot) {
        if (root == nullptr) {
            return;
        }
        int stealRootL = 0;
        int notStealRootL = 0;
        rob(root->left, stealRootL, notStealRootL);
        int stealRootR = 0;
        int notStealRootR = 0;
        rob(root->right, stealRootR, notStealRootR);
        stealRoot = root->val + notStealRootL + notStealRootR;
        notStealRoot = max(stealRootL, notStealRootL) + max(stealRootR, notStealRootR);
    }
    int rob(TreeNode* root) {
        int stealRoot = 0;
        int notStealRoot = 0;
        rob(root, stealRoot, notStealRoot);
        return max(stealRoot, notStealRoot);
    }
};
