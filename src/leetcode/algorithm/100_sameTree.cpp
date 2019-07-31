struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    bool rv = true;
    if (p != nullptr && q != nullptr) {
        rv &= p->val == q->val;
        rv &= isSameTree(p->left, q->left);
        rv &= isSameTree(p->right, q->right);
    } else {
        return false;
    }
    return rv;
}