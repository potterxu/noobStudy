#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> vec;
    stack<TreeNode *> s;
    s.push(root1);
    while (!s.empty()) {
        TreeNode *n = s.top();
        s.pop();
        if (n->right != nullptr) {
            s.push(n->right);
        }
        if (n->left != nullptr) {
            s.push(n->left);
        }
        if (n->left == nullptr && n->right == nullptr) {
            vec.push_back(n->val);
            continue;
        }
    }

    s.push(root2);
    int index = 0;
    bool rv = true;
    while (!s.empty()) {
        TreeNode *n = s.top();
        s.pop();
        if (n->left == nullptr && n->right == nullptr) {
            if (vec[index] == n->val) {
                index++;
                continue;
            } else {
                rv = false;
                break;
            }
        }
        if (n->right != nullptr) {
            s.push(n->right);
        }
        if (n->left != nullptr) {
            s.push(n->left);
        }
    }
    return rv;
}