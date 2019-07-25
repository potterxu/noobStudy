struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int process(TreeNode* root, int toAdd) {
    if (root == nullptr) {
        return toAdd;
    }
    
    root->val += process(root->right, toAdd);
    return process(root->left, root->val);
}
TreeNode* bstToGst(TreeNode* root) {
    process(root, 0);
    return root;
}