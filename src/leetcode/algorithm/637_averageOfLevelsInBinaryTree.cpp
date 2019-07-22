#include <deque>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> rv;
    deque<TreeNode *> q;
    if (root != nullptr) {
        q.push_back(root);
    }
    while (!q.empty()) {
        size_t size = q.size();
        double sum = 0;
        for (size_t i = 0; i < size; ++i) {
            TreeNode *n = q.front();
            q.pop_front();
            sum += n->val;
            if (n->left != nullptr) {
                q.push_back(n->left);
            }
            if (n->right != nullptr) {
                q.push_back(n->right);
            }
        }
        rv.push_back(sum / size);
    }
    return rv;
}