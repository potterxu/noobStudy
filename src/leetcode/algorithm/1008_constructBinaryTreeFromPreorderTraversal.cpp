#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.empty()) {
        return nullptr;
    }
    stack<TreeNode*> s;
    TreeNode *root = new TreeNode(preorder[0]);
    s.push(root);
    for (int i = 1; i < preorder.size(); ++i) {
        TreeNode *top = s.top();
        if (preorder[i] < top->val) {
            top->left = new TreeNode(preorder[i]);
            s.push(top->left);
        } else {
            s.pop();
            while (!s.empty() && preorder[i] > s.top()->val) {
                top = s.top();
                s.pop();
            }
            top->right = new TreeNode(preorder[i]);
            s.push(top->right);
        }
    }
    return root;
}