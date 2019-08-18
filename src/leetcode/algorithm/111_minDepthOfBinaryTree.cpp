struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int min(int a, int b) {
    return a < b ? a : b;
}

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (!root->left) {
        return  minDepth(root->right) + 1;
    }
    if (!root->right) {
        return minDepth(root->left) + 1;
    }
    return min(minDepth(root->right), minDepth(root->left)) + 1;
}