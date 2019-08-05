#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ans = 0;
int max(int a, int b) {
    return a > b ? a : b;
}
int depthOfTree(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    }
    int l = depthOfTree(root->left);
    int r = depthOfTree(root->right);
    ans = max(ans, l + r + 2);
    return max(l, r) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    depthOfTree(root);
    return ans;
}