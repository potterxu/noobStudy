#include <stdlib.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int tile = 0;
int sum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int l = sum(root->left);
    int r = sum(root->right);
    tile += abs(l - r);
    return l + r + root->val;
}

int findTilt(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    sum(root);
    return tile;
}