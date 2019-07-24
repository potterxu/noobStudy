struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int sum(TreeNode *root, int preSum) {
    preSum = preSum << 1;
    preSum += root->val;
    int rv = 0;
    if (root->left == root->right && root->left == nullptr) {
        rv += preSum;
    }
    if (root->left != nullptr) {
        rv += sum(root->left, preSum);
    }
    if (root->right != nullptr) {
        rv += sum(root->right, preSum);
    }
    return rv;
}

int sumRootToLeaf(TreeNode* root) {
    return sum(root, 0);
}