/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (43.00%)
 * Likes:    1869
 * Dislikes: 2151
 * Total Accepted:    381K
 * Total Submissions: 879.8K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that nums[-1] = nums[n] = -∞.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2, 
 * or index number 5 where the peak element is 6.
 * 
 * 
 * Follow up: Your solution should be in logarithmic complexity.
 * 
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        if (nums.size() == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[nums.size()-1] > nums[nums.size()-2]) {
            return nums.size()-1;
        }
        int start = 1;
        int end = nums.size()-2;
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                start = mid;
                break;
            } else if (nums[mid] < nums[mid-1]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return start;
    }
};
