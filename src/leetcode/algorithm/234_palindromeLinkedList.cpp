struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode* head) {
    ListNode* next = head->next;
    head->next = nullptr;
    while (next != nullptr) {
        ListNode* newNext = next->next;
        next->next = head;
        head = next;
        next = newNext;
    }
    return head;
}
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    ListNode *slow = head;
    ListNode *faster = head;
    bool isOdd = true;
    while (faster != nullptr && faster->next != nullptr) {
        slow = slow->next;
        faster = faster->next;
        if (faster->next == nullptr) {
            isOdd = false;
            break;
        }
        faster = faster->next;
    }
    if (isOdd) {
        slow = slow->next;
    }
    slow = reverse(slow);
    faster = head;
    while (slow != nullptr) {
        if (slow->val != faster->val) {
            return false;
        }
        slow = slow->next;
        faster = faster->next;
    }
    return true;
}