struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int find(TreeNode* root, int sum, bool findSum) {
    if (root == nullptr) {
        return 0;
    }
    int rv = 0;
    if (root->val == sum) {
        ++rv;
    }
    if (root->left != nullptr) {
        if (findSum) {
            rv += find(root->left, sum, true);
        }
        rv += find(root->left, sum - root->val, false);
    }
    if (root->right != nullptr) {
        if (findSum) {
            rv += find(root->right, sum, true);
        }
        rv += find(root->right, sum - root->val, false);
    }
    return rv;
}
int pathSum(TreeNode* root, int sum) {
    return find(root, sum, true);
}