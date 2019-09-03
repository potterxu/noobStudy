#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxLevelSum(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    }
    int rv = -1;
    int max = 0x80000000;
    queue<TreeNode*> q;
    q.push(root);
    int level = 1;
    while (!q.empty()) {
        size_t size = q.size();
        int sum = 0;
        for (size_t i = 0; i < size; ++i) {
            TreeNode* root = q.front();
            q.pop();
            sum += root->val;
            if (root->left != nullptr) {
                q.push(root->left);
            }
            if (root->right != nullptr) {
                q.push(root->right);
            }
        }
        if (sum > max) {
            max = sum;
            rv = level;
        }
        ++level;
    }
    return rv;
}