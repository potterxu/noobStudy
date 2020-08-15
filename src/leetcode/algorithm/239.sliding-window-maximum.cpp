/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (42.25%)
 * Likes:    3694
 * Dislikes: 171
 * Total Accepted:    282.1K
 * Total Submissions: 654.9K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Follow up:
 * Could you solve it in linear time?
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

class Solution {
public:
    void clean(deque<int> &q, vector<int> &nums, int i, int k) {
        while (!q.empty() && i - q.front() >= k) {
            q.pop_front();
        }
        while (!q.empty() && nums[q.back()] <= nums[i]) {
            q.pop_back();
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        deque<int> q;
        vector<int> rv;
        for (int i = 0; i < k; ++i) {
            clean(q, nums, i, k);
            q.push_back(i);
        }
        rv.push_back(nums[q.front()]);
        for (int i = k; i <= nums.size() - 1; ++i) {
            clean(q, nums, i, k);
            q.push_back(i);
            rv.push_back(nums[q.front()]);
        }
        return rv;
    }
};
