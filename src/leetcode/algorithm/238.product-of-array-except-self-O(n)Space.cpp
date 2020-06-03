/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (59.46%)
 * Likes:    4579
 * Dislikes: 397
 * Total Accepted:    514.9K
 * Total Submissions: 865.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Constraint: It's guaranteed that the product of the elements of any prefix
 * or suffix of the array (including the whole array) fits in a 32 bit
 * integer.
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        if (nums.size() == 1) {
            return nums;
        }
        vector<int> productFromLeft(nums.size());
        vector<int> productFromRight(nums.size());
        productFromLeft[0] = nums[0];
        productFromRight[nums.size()-1] = nums[nums.size()-1];
        for (int i = 1; i < nums.size() - 1; ++i) {
            productFromLeft[i] =  nums[i] * productFromLeft[i-1];
            productFromRight[nums.size()-1-i] = nums[nums.size()-1-i] * productFromRight[nums.size()-i];
        }
        vector<int> rv(nums.size());
        rv[0] = productFromRight[1];
        rv[nums.size()-1] = productFromLeft[nums.size()-2];
        for (int i = 1; i < nums.size() - 1; ++i) {
            rv[i]= productFromLeft[i-1] * productFromRight[i+1];
        }
        return rv;
    }
};
// @lc code=end
