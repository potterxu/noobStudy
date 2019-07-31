struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int min(int a, int b) {
    return a < b ? a : b;
}

int getMinimumDifference(TreeNode* root) {
    int rv = 0x7FFFFFFF;
    if (root->left != nullptr) {
        TreeNode *leftMax = root->left;
        while (leftMax->right != nullptr) {
            leftMax = leftMax->right;
        }
        rv = min(rv, root->val - leftMax->val);
        rv = min(rv, getMinimumDifference(root->left));
    }
    if (root->right != nullptr) {
        TreeNode *rightMin = root->right;
        while (rightMin->left != nullptr) {
            rightMin = rightMin->left;
        }
        rv = min(rv, rightMin->val - root->val);
        rv = min(rv, getMinimumDifference(root->right));
    }
    return rv;
}