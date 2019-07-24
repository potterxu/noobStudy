#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* recursive(ListNode* head, ListNode* next){
    if (head->next == nullptr) {
        head->next = next;
        return head;
    }
    ListNode *newHead = head->next;
    head->next = next;
    return recursive(newHead, head);
}

ListNode* iterative(ListNode* head){
    stack<ListNode*> s;
    while (head != nullptr) {
        s.push(head);
        head = head->next;
    }
    head = s.top();
    s.pop();
    ListNode *ptr = head;
    while (!s.empty()) {
        ptr->next = s.top();
        s.pop();
        ptr = ptr->next;
    }
    ptr->next = nullptr;
    return head;
}

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    //return recursive(head, nullptr);
    return iterative(head);
}