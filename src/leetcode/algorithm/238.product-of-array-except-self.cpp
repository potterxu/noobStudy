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
        // store product from left
        vector<int> rv(nums.size(), 1);
        int productFromLeft = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            productFromLeft *= nums[i];
            rv[i] = productFromLeft;
        }
        // now rv is productFromLeft array
        // rv[nums.size()-1] = productFromLeft(nums.size()-2)
        rv[nums.size()-1] = rv[nums.size()-2];
        int productFromRight = nums[nums.size()-1];
        for (int i = nums.size()-2; i > 0; --i) {
            rv[i] = productFromRight * rv[i-1];
            productFromRight *= nums[i];
        }
        rv[0] = productFromRight;
        return rv;
    }
};
// @lc code=end
