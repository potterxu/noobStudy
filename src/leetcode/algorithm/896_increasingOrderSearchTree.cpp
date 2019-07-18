#include <deque>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void process(TreeNode *root, deque<TreeNode *> &q) {
    if (root == nullptr) {
        return;
    }
    process(root->left, q);
    q.push_back(root);
    process(root->right, q);
    root->left = nullptr;
    root->right = nullptr;
}

TreeNode* increasingBST(TreeNode* root) {
    deque<TreeNode *> q;
    process(root, q);
    TreeNode *rv = q.front();
    q.pop_front();
    TreeNode *ptr = rv;
    while (!q.empty()) {
        ptr->right = q.front();
        q.pop_front();
        ptr = ptr->right;
    }
    return rv;
}