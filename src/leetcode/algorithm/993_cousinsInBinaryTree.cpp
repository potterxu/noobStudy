#include <deque>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isCousins(TreeNode* root, int x, int y) {
    if (root == nullptr) {
        return false;
    }
    deque<TreeNode *> q;
    q.push_back(root);
    while (!q.empty()) {
        auto itX = find_if(q.begin(), q.end(), [x](TreeNode* it) {
            if (it == nullptr) {
                return false;
            }
            if (it->val == x) {
                return true;
            }
            return false;
        });
        auto itY = find_if(q.begin(), q.end(), [y](TreeNode* it){
            if (it == nullptr) {
                return false;
            }
            if (it->val == y) {
                return true;
            }
            return false;
        });
        if (itX != q.end() && itY != q.end()) {
            if (itX - itY >= 2 || itY - itX >= 2){
                return true;
            }
        }
        size_t size = q.size();
        for (size_t i = 0; i < size; ++i) {
            TreeNode *n = q.front();
            q.pop_front();
            if (n == nullptr) {
                continue;
            }
            if (n->left != nullptr) {
                q.push_back(n->left);
            }
            if (n->right != nullptr) {
                q.push_back(n->right);
            }
            if (n->left != nullptr || n->right != nullptr) {
                q.push_back(nullptr);
            }
        }
        
    }
    return false;
}