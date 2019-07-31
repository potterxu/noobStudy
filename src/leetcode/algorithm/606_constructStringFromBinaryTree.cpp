#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string tree2str(TreeNode* t) {
    string rv;
    if (t == nullptr) {
        return rv;
    }
    rv += to_string(t->val);
    if (t->right != nullptr) {
        rv += "(";
        rv += tree2str(t->left);
        rv += ")";
        rv += "(";
        rv += tree2str(t->right);
        rv += ")";
    } else if (t->left != nullptr) {
        rv += "(";
        rv += tree2str(t->left);
        rv += ")";
    }
    return rv;
}