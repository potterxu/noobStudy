struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool findVal(TreeNode* root, int k) {
    if (root != nullptr) {
        if (k < root->val) {
            return findVal(root->left, k);
        } else if (k > root->val) {
            return findVal(root->right, k);
        } else {
            return true;
        }
    }
    return false;
}

bool findTarget(TreeNode* root, TreeNode* node, int k) {
    if (node == nullptr) {
        return false;
    }
    bool rv = false;
    if (node->val != k - node->val) {
        rv = findVal(root, k - node->val);
    }
    if (!rv) {
        rv |= findTarget(root, node->left, k);
    }
    if (!rv) {
        rv |= findTarget(root, node->right, k);
    }
    return rv;
}
bool findTarget(TreeNode* root, int k) {
    return findTarget(root, root, k);
}