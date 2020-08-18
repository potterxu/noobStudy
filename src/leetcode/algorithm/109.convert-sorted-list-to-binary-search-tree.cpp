/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (46.50%)
 * Likes:    2155
 * Dislikes: 87
 * Total Accepted:    250.7K
 * Total Submissions: 524.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given the head of a singly linked list where elements are sorted in
 * ascending order, convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: One possible answer is [0,-3,9,-10,null,5], which represents
 * the shown height balanced BST.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [0]
 * Output: [0]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = [1,3]
 * Output: [3,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The numner of nodes in head is in the range [0, 2 * 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if (!head || head == tail) {
            return nullptr;
        }
        if (head->next == tail) {
            return new TreeNode(head->val);
        }
        auto ptr1 = head;
        auto ptr2 = head;
        while (ptr2 != tail && ptr2->next != tail) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        //printf("%d %d\n", head->val, ptr1->val);
        TreeNode *root = new TreeNode(ptr1->val);
        root->left = sortedListToBST(head, ptr1);
        root->right = sortedListToBST(ptr1->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
};
