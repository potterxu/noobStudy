/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 *
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
 *
 * algorithms
 * Hard (51.73%)
 * Likes:    1078
 * Dislikes: 25
 * Total Accepted:    38.1K
 * Total Submissions: 72.9K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * You have k lists of sorted integers in ascending order. Find the smallest
 * range that includes at least one number from each of the k lists.
 * 
 * We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c
 * if b-a == d-c.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * Output: [20,24]
 * Explanation: 
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given list may contain duplicates, so ascending order means >= here.
 * 1 <= k <= 3500
 * -10^5 <= value of elements <= 10^5.
 * 
 * 
 */

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> p(nums.size(), 0);
        auto cmp = [&](const int a, const int b) -> bool {
            return nums[a][p[a]] >= nums[b][p[b]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int curMax = INT_MIN;
        for (int i = 0; i <nums.size(); ++i) {
            pq.push(i);
            curMax = max(curMax, nums[i][p[i]]);
        }
        int t = pq.top();
        int rvL = -100001;
        int rvR = 100001;
        while (p[t] < nums[t].size()) {
            t = pq.top();
            //printf("%d, %d, %d, %d\n", t, p[t], rvL, rvR);
            int newL = nums[t][p[t]];
            if (curMax - newL < rvR - rvL) {
                rvL = newL;
                rvR = curMax;
            }
            pq.pop();
            p[t]++;
            if (p[t] >= nums[t].size()) {
                break;
            }
            curMax = max(curMax, nums[t][p[t]]);
            pq.push(t);
        }
        return vector<int> {rvL, rvR};
    }
};
