struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int m = 0;
int rv = -1;

int min(int a, int b) {
    return a < b ? a : b;
}

void dfs(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    if (root->val == m) {
        dfs(root->left);
        dfs(root->right);
    } else if (root->val > m) {
        if (rv == -1) {
            rv = root->val;
        } else {
            rv = min(root->val, rv);
        }
    }
}

int findSecondMinimumValue(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    }
    m = root->val;
    dfs(root);
    return rv;
}