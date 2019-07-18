struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) {
        return nullptr;
    } else if (t1 == nullptr && t2 != nullptr) {
        return t2;
    } else if (t1 != nullptr && t2 == nullptr) {
        return t1;
    } else {
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
    }
    return t1;
}