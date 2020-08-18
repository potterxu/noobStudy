/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (59.14%)
 * Likes:    2758
 * Dislikes: 67
 * Total Accepted:    419.4K
 * Total Submissions: 695K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * Output: 3
 * 
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of elements of the BST is between 1 to 10^4.
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
    int kthSmallest(TreeNode* root, int k) {
        // morris
        TreeNode *cur = root;
        TreeNode *leftMostRight;
        TreeNode *rv = nullptr;
        while (cur != nullptr) {
            leftMostRight = cur->left;
            if (leftMostRight != nullptr) {
                while (leftMostRight->right != nullptr && leftMostRight->right != cur) {
                    leftMostRight = leftMostRight->right;
                }
                if (leftMostRight->right == nullptr) {
                    // left tree not visite before, mark the return point and go to the left tree
                    leftMostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    // reset pointer
                    leftMostRight->right = nullptr;
                }
            } else {
                // no left tree
            }
            // already visited left tree, now visit cur, then right tree, in-order traverse
            if (rv == nullptr && k == 1) {
                rv = cur;
            } else if (k > 1) {
                --k;
            }
            cur = cur->right;
        }
        return rv->val;
    }
};
