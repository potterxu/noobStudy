/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (35.97%)
 * Likes:    2042
 * Dislikes: 120
 * Total Accepted:    241.3K
 * Total Submissions: 649.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        stack<ListNode*> s;
        auto p = head;
        int size = 0;
        while (p != nullptr) {
            s.push(p);
            p = p->next;
            ++size;
        }
        p = head;
        while (size > 2) {
            s.top()->next = p->next;
            p->next = s.top();
            p = s.top()->next;
            s.pop();
            size -= 2;
        }
        if (size == 1) {
            p->next = nullptr;
        } else if (size == 2) {
            s.top()->next = nullptr;
        }
    }
};
