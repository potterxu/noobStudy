/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.19%)
 * Likes:    3644
 * Dislikes: 1302
 * Total Accepted:    388K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

class Solution {
public:
    int findFisrtLargerThan(vector<int>& nums, int targetI) {
        int start = targetI+1;
        int end = nums.size()-1;
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] <= nums[targetI]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return start-1;
    }
    void nextPermutation(vector<int>& nums) {
        // change the leftmost possible number
        // loop from back to front and the number should be increasing
        // find the first one nums[i] that is decreasing
        // swap nums[i] with the smallest nums[j] that is larger than nums[i] (i < j < end)
        // finally reverse i+1 to end
        if (nums.size() < 2) {
            return;
        }
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] < nums[i+1]) {
                // find the required nums[j]
                int j = findFisrtLargerThan(nums, i);
                swap(nums[i], nums[j]);
                break;
            }
            --i;
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};
