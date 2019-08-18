struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
    while (head != nullptr) {
        if (head->val != val) {
            break;
        }
        head = head->next;
    }
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *ptr = head;
    while (ptr->next != nullptr) {
        if (ptr->next->val == val) {
            ptr->next = ptr->next->next;
        } else {
            ptr = ptr->next;
        }
    }
    return head;
}