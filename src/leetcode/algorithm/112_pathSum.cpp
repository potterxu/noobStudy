struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
        return false;
    }   
    sum -= root->val;
    if (root->left == nullptr && root->right == nullptr) {
        if (sum == 0) {
            return true;
        } else {
            return false;
        }
    }
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}