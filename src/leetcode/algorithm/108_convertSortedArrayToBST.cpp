#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* process(vector<int>& nums, int start, int end) {
    if (start > end) {
        return nullptr;
    } else if (start == end) {
        return new TreeNode(nums[start]);
    }
    int rootI = (start + end) / 2;
    TreeNode *root = new TreeNode(nums[rootI]);
    root->left = process(nums, start, rootI - 1);
    root->right = process(nums, rootI + 1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return process(nums, 0, nums.size() - 1);
}