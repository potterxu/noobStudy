struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode *stepOne = head;
    ListNode *stepTwo = head;
    if (head == nullptr) {
        return nullptr;
    } else if (head->next == nullptr) {
        return head;
    }
    while (stepTwo != nullptr && stepTwo->next != nullptr) {
        stepOne = stepOne->next;
        stepTwo = stepTwo->next;
        if (stepTwo != nullptr) {
            stepTwo = stepTwo->next;
        }
    }
    return stepOne;
}