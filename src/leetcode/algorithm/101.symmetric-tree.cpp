/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (46.27%)
 * Total Accepted:    620.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Follow up: Solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        stack<TreeNode*> l;
        stack<TreeNode*> r;
        l.push(root->left);
        r.push(root->right);
        while(!l.empty() || !r.empty()) {
            size_t s = l.size();
            for (int i = 0; i < s; ++i) {
                auto ln = l.top();
                auto rn = r.top();
                l.pop();
                r.pop();
                if (!ln && !rn) {
                    continue;
                }
                if (ln && rn) {
                    if (ln->val != rn->val) {
                        return false;
                    }
                    l.push(ln->left);
                    l.push(ln->right);
                    r.push(rn->right);
                    r.push(rn->left);
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};
