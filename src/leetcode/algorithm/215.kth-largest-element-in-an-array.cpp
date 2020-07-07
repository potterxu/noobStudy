/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (54.12%)
 * Likes:    3651
 * Dislikes: 248
 * Total Accepted:    622.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

class Solution {
public:
    void siftDown(vector<int> &nums, int n, int end) {
        if (n >= end) {
            return;
        }
        while (n <= (end - 1) / 2) {
            int maxChild = n * 2 + 1;
            if (maxChild+1 <= end && nums[maxChild+1] >= nums[maxChild]) {
                maxChild += 1;
            }
            if (nums[maxChild] <= nums[n]) {
                break;
            }
            swap(nums[n], nums[maxChild]);
            n = maxChild;
        }
    }

    void heaplify(vector<int> &nums) {
        for (int i = nums.size() - 1; i >= 0; --i) {
            siftDown(nums, i, nums.size()-1);
        }
    }

    int heap_sort_solution(vector<int> &nums, int k) {
        heaplify(nums); // MaxHeap
        for (int i = nums.size() - 1; i > 0 ; --i) {
            swap(nums[0], nums[i]);
            siftDown(nums, 0, i-1);
        }
        return nums[nums.size()-k];
    }

    int priority_queue_solution(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;
        for (int num : nums) {
            q.push(num);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }

    int quick_select_solution(vector<int>& nums, int k, int Start, int End) {
        int start = Start;
        int end = End;
        int pivotI = start;
        ++start;
        while (start <= end) {
            if (nums[end] >= nums[pivotI]) {
                --end;
                continue;
            }
            if (nums[start] < nums[pivotI]) {
                ++start;
                continue;
            }
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
        if (end == nums.size() - k) {
            return nums[pivotI];
        }
        swap(nums[pivotI], nums[end]);
        if (end > nums.size() - k) {
            return quick_select_solution(nums, k, Start, end - 1);
        }
        return quick_select_solution(nums, k, end + 1, End);
    }

    int findKthLargest(vector<int>& nums, int k) {
        // return priority_queue_solution(nums, k);
        // return quick_select_solution(nums, k, 0, nums.size() - 1);
        return heap_sort_solution(nums, k);
    }
};
