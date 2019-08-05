struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    ListNode *n = l2;
    l2 = l2->next;
    if (n->val < l1->val) {
        n->next = l1;
        l1 = n;
    } else {
        ListNode *ptr = l1;
        while (ptr != nullptr) {
            if (ptr->next == nullptr) {
                ptr->next = n;
                n->next = nullptr;
                break;
            } else {
                if (n->val < ptr->next->val) {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
            ptr = ptr->next;
        }
    }
    mergeTwoLists(n, l2);
    return l1;
}