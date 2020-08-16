/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
 *
 * https://leetcode.com/problems/binary-tree-pruning/description/
 *
 * algorithms
 * Medium (74.00%)
 * Likes:    1075
 * Dislikes: 39
 * Total Accepted:    66.7K
 * Total Submissions: 89.6K
 * Testcase Example:  '[1,null,0,0,1]'
 *
 * We are given the head node root of a binary tree, where additionally every
 * node's value is either a 0 or a 1.
 * 
 * Return the same tree where every subtree (of the given tree) not containing
 * a 1 has been removed.
 * 
 * (Recall that the subtree of a node X is X, plus every node that is a
 * descendant of X.)
 * 
 * 
 * Example 1:
 * Input: [1,null,0,0,1]
 * Output: [1,null,0,null,1]
 * ⁠
 * Explanation: 
 * Only the red nodes satisfy the property "every subtree not containing a 1".
 * The diagram on the right represents the answer.
 * 
 * 
 * 
 * 
 * 
 * Example 2:
 * Input: [1,0,1,0,0,0,1]
 * Output: [1,null,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 3:
 * Input: [1,1,0,1,1,0,1,0]
 * Output: [1,1,0,1,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * The binary tree will have at most 200 nodes.
 * The value of each node will only be 0 or 1.
 * 
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == 0) {
                return nullptr;
            }
        }
        return root;
    }
};
