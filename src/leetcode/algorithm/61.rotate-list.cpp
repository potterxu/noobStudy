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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        int size = 1;
        auto end = head;
        while (end->next != nullptr) {
            ++size;
            end = end->next;
        }
        k %= size;
        if (k == 0) {
            return head;
        }
        ListNode *newHeadprev = nullptr;
        auto newHead = head;
        for (int i = 0; i < size - k; ++i) {
            newHeadprev = newHead;
            newHead = newHead->next;
        }
        newHeadprev->next = nullptr;
        end->next = head;
        return newHead;
    }
};
