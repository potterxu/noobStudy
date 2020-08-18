/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (39.43%)
 * Likes:    5086
 * Dislikes: 297
 * Total Accepted:    678.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Given an array of linked-lists lists, each linked list is sorted in
 * ascending order.
 * 
 * Merge all the linked-lists into one sort linked-list and return it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: lists = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: lists = [[]]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length won't exceed 10^4.
 * 
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct myCmp {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKListsWithpq(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, myCmp> q;
        for (ListNode *n : lists) {
            if (n) {
                q.push(n);
            }
        }
        ListNode fakeRoot(0);
        ListNode *node = &fakeRoot;
        while (!q.empty()) {
            node->next = q.top();
            q.pop();
            node = node->next;
            if (node->next) {
                q.push(node->next);
            }
            node->next = nullptr;
        }
        return fakeRoot.next;
    }

    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode fakeRoot(0);
        ListNode *n = &fakeRoot;
        while(a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                n->next = a;
                a = a->next;
            } else {
                n->next = b;
                b = b->next;
            }
            n = n->next;
        }
        if (a != nullptr) {
            n->next = a;
        } else {
            n->next = b;
        }
        return fakeRoot.next;
    }
    void merge(vector<ListNode*>& lists, int interval) {
        for (int i = 0; i + interval < lists.size(); i += 2*interval) {
            //printf("%d, %d\n", i, i+interval);
            lists[i] = merge(lists[i], lists[i+interval]);
        }
        if ((lists.size()-1) / 2 >= interval) {
            merge(lists, interval * 2);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        merge(lists, 1);
        return lists[0];
    }
};
