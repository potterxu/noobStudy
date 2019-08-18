struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    bool AFirst = true;
    bool BFirst = true;
    ListNode *ptrA = headA;
    ListNode *ptrB = headB;
    while (true) {
        if (ptrA == ptrB) {
            return ptrA;
        }
        ptrA = ptrA->next;
        if (ptrA == nullptr) {
            if (AFirst) {
                ptrA = headB;
                AFirst = false;
            } else {
                break;
            }
        }
        ptrB = ptrB->next;
        if (ptrB == nullptr) {
            if (BFirst) {
                ptrB = headA;
                BFirst = false;
            } else {
                break;
            }
        }
    }
    return nullptr;
}