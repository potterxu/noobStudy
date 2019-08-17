struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    ListNode *step1 = head;
    ListNode *step2 = head;
    while (step2 != nullptr) {
        step1 = step1->next;
        if (step2->next == nullptr) {
            return false;
        }
        step2 = step2->next->next;
        if (step1 == step2) {
            return true;
        }
    }
    return false;
}