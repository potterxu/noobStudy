/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
 *
 * https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Hard (69.70%)
 * Likes:    407
 * Dislikes: 14
 * Total Accepted:    17.9K
 * Total Submissions: 25.7K
 * Testcase Example:  '"1-2--3--4-5--6--7"'
 *
 * We run a preorder depth first search on the root of a binary tree.
 * 
 * At each node in this traversal, we output D dashes (where D is the depth of
 * this node), then we output the value of this node.  (If the depth of a node
 * is D, the depth of its immediate child is D+1.  The depth of the root node
 * is 0.)
 * 
 * If a node has only one child, that child is guaranteed to be the left
 * child.
 * 
 * Given the output S of this traversal, recover the tree and return its
 * root.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: "1-2--3--4-5--6--7"
 * Output: [1,2,5,3,4,6,7]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: "1-2--3---4-5--6---7"
 * Output: [1,2,5,3,null,6,null,4,null,7]
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: "1-401--349---90--88"
 * Output: [1,401,null,349,88,90]
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the original tree is between 1 and 1000.
 * Each node will have a value between 1 and 10^9.
 * 
 * 
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void addNewNode(stack<TreeNode *> &s, TreeNode *node, int layer) {
        while (layer < s.size()) {
            s.pop();
        }
        if (!s.empty()) {
            //printf("%d\n", s.top()->val);
            if (s.top()->left == nullptr) {
                s.top()->left = node;
            } else {
                s.top()->right = node;
            }
        }
        s.push(node);
    }
    TreeNode* recoverFromPreorder(string S) {
        TreeNode *root = nullptr;
        int ptr = 0;
        int val = 0;
        int layer = 0;
        stack<TreeNode *> s;
        while (ptr < S.size()) {
            if (S[ptr] == '-') {
                ++layer;
            } else {
                val *= 10;
                val += S[ptr] - '0';
                if (S[ptr+1] == '-') {
                    // next is start of a new number;
                    auto node = new TreeNode(val);
                    if (!root) {
                        root = node;
                    }
                    //printf("%d, %d\n", val, layer);
                    addNewNode(s, node, layer);
                    val = 0;
                    layer = 0;
                } 
            }
            ++ptr;
        }
        auto node = new TreeNode(val);
        if (!root) {
            root = node;
        }
        addNewNode(s, node, layer);
        return root;
    }
};