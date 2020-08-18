/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (29.06%)
 * Likes:    7550
 * Dislikes: 1187
 * Total Accepted:    717.5K
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // split nums1 to i and l1 - i
        // split nums2 to j and l2 - j
        // i+j = (l1+l2+1)/2
        // nums2[j] >= nums1[i-1]
        // nums1[i] >= nums2[j-1]

        int numsAtLeft = nums1.size() + (nums2.size()-nums1.size()+1)/2;
        int start1 = 0;
        int end1 = min((int)nums1.size(), numsAtLeft);
        bool odd = (nums1.size() + nums2.size()) & 1;
        int i = 0;
        int j = numsAtLeft-i;
        while (start1 <= end1) {
            i = start1+(end1-start1)/2;
            j = numsAtLeft - i;
            if (j > nums2.size()) {
                start1 = i+1;
                continue;
            }
            if ((i >= 0 && i < nums1.size()) && (j >= 1 && j < nums2.size()+1)) {
                if (nums1[i] < nums2[j-1]) {
                    start1 = i+1;
                    continue;
                }
            }
            if ((i >= 1 && i < nums1.size()+1) && (j >= 0 && j < nums2.size())) {
                if (nums2[j] < nums1[i-1]) {
                    end1 = i - 1;
                    continue; 
                } 
            }
            break;
        }
        int rv1 = INT_MIN;
        if (i > 0) {
            rv1 = max(rv1, nums1[i-1]);
        }
        if (j > 0) {
            rv1 = max(rv1, nums2[j-1]);
        }
        if (odd) {
            return rv1;
        }
        int rv2 = INT_MAX;
        if (i < nums1.size()) {
            rv2 = min(rv2, nums1[i]);
        }
        if (j < nums2.size()) {
            rv2 = min(rv2, nums2[j]);
        }
        return (rv1+rv2)/2.0;
    }
};
