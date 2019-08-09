struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSame(TreeNode* left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    if (left != nullptr && right != nullptr ){
        if (left->val != right->val) {
            return false;
        }
        bool rv = isSame(left->left, right->right);
        rv &= isSame(left->right, right->left);
        return rv;
    }
    return false;
}
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    return isSame(root->left, root->right);
}