struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *ptr = root;
    while (ptr != nullptr) {
        if (p->val < ptr->val) {
            if (q->val < ptr->val) {
                ptr = ptr->left;
                continue;
            } else {
                break;
            }
        } else if (p->val == ptr->val) {
            return ptr;
        } else {
            if (q->val > ptr->val) {
                ptr = ptr->right;
                continue;
            } else {
                break;
            }
        }
    }
    return ptr;
}