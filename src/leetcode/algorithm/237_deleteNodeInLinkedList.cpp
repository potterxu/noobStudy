#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode* node) {
    swap(node->val, node->next->val);
    ListNode* tmp = node->next;
    node->next = node->next->next;
    delete tmp;
}