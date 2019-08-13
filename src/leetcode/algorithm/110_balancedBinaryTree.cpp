struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int max(int a, int b) {
    return a > b ? a : b;
}

int processHeight(TreeNode* root, bool &rv) {
    if (root == nullptr) {
        return 0;
    }
    int left = processHeight(root->left, rv);
    int right = processHeight(root->right, rv);
    if (rv) {
        if (left - right > 1 || left - right < -1) {
            rv = false;
        }
    }
    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    bool rv = true;
    processHeight(root, rv);
    return rv;
}