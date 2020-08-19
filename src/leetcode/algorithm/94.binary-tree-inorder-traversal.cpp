/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (62.25%)
 * Likes:    3395
 * Dislikes: 141
 * Total Accepted:    768.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> stackMethod(TreeNode* root) {
        vector<int> rv;
        if (!root) {
            return rv;
        }
        stack<TreeNode*> s;
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
        while (!s.empty()) {
            root = s.top();
            s.pop();
            rv.push_back(root->val);
            root = root->right;
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
        }
        return rv;
    }

    vector<int> morris(TreeNode* root) {
        vector<int> rv;
        if (!root) {
            return rv;
        }
        TreeNode *cur = root;
        TreeNode *leftMostRight = nullptr;
        while (cur) {
            leftMostRight = cur->left;
            if (leftMostRight) {
                while (leftMostRight->right && leftMostRight->right != cur) {
                    leftMostRight = leftMostRight->right;
                }
                if (!leftMostRight->right) {
                    leftMostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    leftMostRight->right = nullptr;
                }
            }
            rv.push_back(cur->val);
            cur = cur->right;
        }
        return rv;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        return morris(root);
    }
};
