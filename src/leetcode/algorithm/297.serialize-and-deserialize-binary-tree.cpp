/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (46.51%)
 * Likes:    2855
 * Dislikes: 140
 * Total Accepted:    314.1K
 * Total Submissions: 672.7K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "[]";
        }
        queue<TreeNode*> q;
        q.push(root);
        bool needComa = false;
        stringstream ss;
        ss << "[";
        while(!q.empty()) {
            bool layerAllNull = true;
            size_t size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *ptr = q.front();
                q.pop();
                writeVal(ptr, ss, needComa);
                needComa = true;
                bool noChildren = true;
                if (ptr) {
                    q.push(ptr->left);
                    q.push(ptr->right);
                    noChildren = !ptr->left && !ptr->right;
                }
                if (layerAllNull) {
                    layerAllNull = noChildren;
                }
            }
            if (layerAllNull) {
                break;
            }
        }
        ss << "]";
        //printf("%s\n", ss.str().c_str());
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() < 3) {
            return nullptr;
        }
        TreeNode * root = nullptr;
        queue<TreeNode *> q;
        int val = 0;
        int index = 1;
        bool left = false;
        bool negative = false;
        while (index < data.size()) {
            if (data[index] >= '0' && data[index] <= '9') {
                val *= 10;
                val += data[index] - '0';
                ++index;
                continue;
            } else if (data[index] == '-') {
                negative = true;
                ++index;
                continue;
            }
            TreeNode *node = nullptr;
            if (data[index] == ',' || data[index] == ']') {
                if (negative) {
                    val = -val;
                }
                node = new TreeNode(val);
                val = 0;
                negative = false;
                ++index;
            } else if (data[index] == 'n') {
                index += 5;
            }
            if (q.empty()) {
                root = node;
                q.push(node);
            } else {
                addNode(q, node, left);
            }
            //serialize(root);
        }
        return root;
    }

    void writeVal(TreeNode *node, stringstream &ss, bool needComa) {
        if (needComa) {
            ss << ",";
        }
        if (!node) {
            ss << "null";
        } else {
            ss << node->val;
        }
    }
    void addNode(queue<TreeNode *> &q, TreeNode *node, bool &left) {
        if (!left) {
            q.front()->left = node;
            left = true;
        } else {
            q.front()->right = node;
            q.pop();
            left = false;
        }
        if (node) {
            q.push(node);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
