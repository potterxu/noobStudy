/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (35.69%)
 * Likes:    3631
 * Dislikes: 154
 * Total Accepted:    520K
 * Total Submissions: 1.4M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

class Solution {
public:
    void search(vector<int> &nums, int target, int start, int end, vector<int> &rv) {
        //printf("%d, %d\n", start, end);
        if (start > end) {
            return;
        }
        if (nums[end] < target || nums[start] > target) {
            return;
        }
        int mid = start + (end-start) /2;
        if (nums[mid] == target) {
            if (rv[0] == -1) {
                rv[0] = mid;
            } else {
                rv[0] = min(rv[0], mid);
            }
            if (rv[1] == -1) {
                rv[1] = mid;
            } else {
                rv[1] = max(rv[1], mid);
            }
        }
        search(nums, target, start, mid-1, rv);
        search(nums, target, mid+1, end, rv);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rv(2, -1);
        search(nums, target, 0, nums.size()-1, rv);
        return rv;
    }
};
