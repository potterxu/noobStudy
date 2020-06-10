/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (61.34%)
 * Likes:    4260
 * Dislikes: 87
 * Total Accepted:    957.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
 */

// @lc code=start
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* iterate(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode* cur = head->next;
        ListNode* pre = head;
        pre->next = nullptr;
        while (cur != nullptr) {
            ListNode* tmpCur = cur;
            cur = cur->next;
            tmpCur->next = pre;
            pre = tmpCur;
        }
        return pre;
    }

    ListNode* recursive(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode* newHead = head;
        if (head->next != nullptr) {
            newHead = recursive(head->next);
            head->next->next = head;
            head->next = nullptr;
        }
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        return iterate(head);
        // return recursive(head);
    }
};
// @lc code=end
