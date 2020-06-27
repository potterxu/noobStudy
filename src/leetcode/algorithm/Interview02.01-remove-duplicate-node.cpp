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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head) {
            return head;
        }
        unordered_map<int, int> m;
        m[head->val] = 1;
        ListNode *node = head;
        while (node->next) {
            if (m.find(node->next->val) != m.end()) {
                ListNode *toDelete = node->next;
                node->next = node->next->next;
            } else {
                m[node->next->val] = 1;
                node = node->next;
            }
        }
        return head;
    }
};