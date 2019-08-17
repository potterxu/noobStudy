// #include <vector>
// using namespace std;
// 
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// 
// vector<int> rv;
// int maxCount = 0;
// int count = 0;
// int curInt = -1;
// 
// void inorderTraverse(TreeNode* root) {
//     if (root->left != nullptr) {
//         inorderTraverse(root->left);
//     }
//     if (curInt == -1) {
//         curInt = root->val;
//         count = 1;
//     } else if (root->val == curInt) {
//         ++count;
//     } else {
//         if (maxCount == count) {
//             rv.push_back(curInt);
//         } else if (count > maxCount) {
//             rv.clear();
//             rv.push_back(curInt);
//             maxCount = count;
//         }
//         curInt = root->val;
//         count = 1;
//     }
//     if (root->right != nullptr) {
//         inorderTraverse(root->right);
//     }
// }
// 
// vector<int> findMode(TreeNode* root) {
//     if (root == nullptr) {
//         return rv;
//     }
//     inorderTraverse(root);
//     if (maxCount == count) {
//         rv.push_back(curInt);
//     } else if (count > maxCount) {
//         rv.clear();
//         rv.push_back(curInt);
//     }
//     return rv;
// }