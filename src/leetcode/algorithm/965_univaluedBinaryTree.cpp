struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isUnivalTree(TreeNode* root) {
    bool rv = true;
    if (root == nullptr) {
        return rv;
    }
    if (root->left != nullptr) {
        rv &= root->val == root->left->val;
    }
    if (root->right != nullptr) {
        rv &= root->val == root->right->val;
    }
    rv &= isUnivalTree(root->left);
    rv &= isUnivalTree(root->right);
    return rv;
}