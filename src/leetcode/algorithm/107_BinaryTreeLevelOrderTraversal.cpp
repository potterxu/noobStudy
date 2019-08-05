#include <vector>
#include <deque>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    stack<vector<int>> s;
    deque<TreeNode *> q;
    vector<vector<int>> rv;
    if (root == nullptr) {
        return rv;
    }
    q.push_back(root);
    while (!q.empty()) {
        size_t size = q.size();
        vector<int> v;
        for (size_t i = 0; i < size; ++i) {
            TreeNode *n = q.front();
            q.pop_front();
            v.push_back(n->val);
            if (n->left != nullptr) {
                q.push_back(n->left);
            }
            if (n->right != nullptr) {
                q.push_back(n->right);
            }
        }
        s.push(v);
    }
    while (!s.empty()) {
        rv.push_back(s.top());
        s.pop();
    }
    return rv;
}