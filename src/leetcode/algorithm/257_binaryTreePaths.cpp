#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* root, vector<string> &rv, string str = "") {
    str += to_string(root->val);
    if (root->right == nullptr && root->left == nullptr) {
        rv.push_back(str);
        return;
    }
    str += "->";
    if (root->right != nullptr) {
        dfs(root->right, rv, str);
    }
    if (root->left != nullptr) {
        dfs(root->left, rv, str);
    }
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> rv;
    if (root != nullptr) {
        dfs(root, rv);
    }
    return rv;
}