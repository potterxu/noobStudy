struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* ptr = head;
    ListNode* ptr2 = head->next;
    while (ptr2 != nullptr) {
        if (ptr2->val != ptr->val) {
            ptr->next = ptr2;
            ptr = ptr2;
        }
        ptr2 = ptr2->next;
    }
    ptr->next = nullptr;
    return head;
}