struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isEqual(TreeNode *s, TreeNode* t) {
    if (s == nullptr && t == nullptr) {
        return true;
    }
    if (s != nullptr && t != nullptr) {
        int rv = s->val == t->val;
        rv &= isEqual(s->left, t->left);
        rv &= isEqual(s->right, t->right);
        return rv;
    }
    return false;
}
bool isSubtree(TreeNode* s, TreeNode* t) {
    bool rv = false;
    if (s->val == t->val) {
        rv = true;
        rv &= isEqual(s->left, t->left);
        rv &= isEqual(s->right, t->right);
    }      
    if (s->left != nullptr) {
        rv |= isSubtree(s->left, t);
    }
    if (s->right != nullptr) {
        rv |= isSubtree(s->right, t);
    }
    return rv;
}