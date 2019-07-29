struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int rv = 0;
    if (root->left != nullptr) {
        if (root->left->left == nullptr && root->left->right == nullptr) {
            rv += root->left->val;
        } else {
            rv += sumOfLeftLeaves(root->left);
        }
    }
    if (root->right != nullptr) {
        rv += sumOfLeftLeaves(root->right);
    }
    return rv;
}