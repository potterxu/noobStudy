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
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (root == nullptr) {
			return nullptr;
		}
		if (root->val < L) {
			root = trimBST(root->right, L, R);
		} else if (root->val > R) {
			root = trimBST(root->left, L, R);
		} else{
			root->right = trimBST(root->right, L, R);
			root->left = trimBST(root->left, L, R);
		}
		return root;
	}
};
