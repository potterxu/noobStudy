/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (38.80%)
 * Likes:    1625
 * Dislikes: 77
 * Total Accepted:    167.9K
 * Total Submissions: 423.5K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * Output: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * Output: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 
 * Follow up:
 * 
 * 
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
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
    void morris(TreeNode *root) {
        TreeNode *node1 = nullptr;
        TreeNode *node2 = nullptr;
        TreeNode *cur = root;
        TreeNode *mostRight = nullptr;
        TreeNode *preNode = nullptr;
        while (cur != nullptr) {
            mostRight = cur->left;
            if (mostRight != nullptr) {
                while (mostRight->right != nullptr && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == nullptr) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    mostRight->right = nullptr;
                }
            } else {
                // no left tree
            }
            if (preNode != nullptr && preNode->val > cur->val) {
                node2 = cur;
                if (node1 == nullptr) {
                    node1 = preNode;
                } else {
                    //break;
                }
            }
            preNode = cur;
            cur = cur->right;
        }
        swap(node1->val, node2->val);
    }

    void inorderWithStack(TreeNode* root) {
        TreeNode *node1 = nullptr;
        TreeNode *node2 = nullptr;
        TreeNode *preNode = nullptr;
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (preNode != nullptr && preNode->val > root->val) {
                node2 = root;
                if (node1 == nullptr) {
                    node1 = preNode;
                } else {
                    break;
                }
            }
            preNode = root;
            root = root->right;
        }
        swap(node1->val, node2->val);
    }

    void recoverTree(TreeNode* root) {
        //inorderWithStack(root);
        morris(root);
    }
};




