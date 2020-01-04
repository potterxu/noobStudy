/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		ListNode *fake = new ListNode(0);
		fake->next = head;
		unordered_map<int, ListNode*> m;
		ListNode *n = fake;
		int sum = 0;
		while (n != nullptr) {
			sum += n->val;
			if (m.find(sum) != m.end()) {
				m[sum]->next = n->next;
				n = fake;
				m.clear();
				sum = 0;
				continue;
			}
			m[sum] = n;
			n = n->next;
		}
		return fake->next;
	}
};
