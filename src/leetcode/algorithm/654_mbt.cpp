#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    int max = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[max]) {
            max = i;
        }
    }
    TreeNode *root = new TreeNode(nums[max]);
    vector<int> left(nums.begin(), nums.begin() + max);
    root->left = constructMaximumBinaryTree(left);
    vector<int> right(nums.begin() + max + 1, nums.end());
    root->right = constructMaximumBinaryTree(right);
    return root;
}