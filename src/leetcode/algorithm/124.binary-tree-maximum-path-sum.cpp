/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (33.81%)
 * Likes:    3538
 * Dislikes: 283
 * Total Accepted:    361.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
 * 
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
    int process(TreeNode *node, int &maxSum) {
        if (!node) {
            return 0;
        }
        int maxL = max(0, process(node->left, maxSum));
        int maxR = max(0, process(node->right, maxSum));
        maxSum = max(maxSum, node->val + maxL + maxR);
        return node->val + max(maxL, maxR);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        process(root, maxSum);
        return maxSum;
    }
};
