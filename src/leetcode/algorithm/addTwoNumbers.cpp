/*
 * You are given two non-empty linked lists representing two non-negative
 * integers.
 *
 * The digits are stored in reverse order and each of their nodes contain a
 * single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example: Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* sumNodes(ListNode* l1, ListNode* l2, int carry = 0) {
    if (l1 == nullptr && l2 == nullptr && carry == 0) {
        return nullptr;
    }

    ListNode *rv = new ListNode(0);
    ListNode *l1_next = nullptr;
    ListNode *l2_next = nullptr;
    int sum = carry;

    if (l1 != nullptr) {
        sum += l1->val;
        l1_next = l1->next;
    }

    if (l2 != nullptr) {
        sum += l2->val;
        l2_next = l2->next;
    }

    rv->val = sum % 10;
    rv->next = sumNodes(l1_next, l2_next, sum / 10);
    return rv;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return sumNodes(l1, l2);
}