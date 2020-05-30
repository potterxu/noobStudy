/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (34.28%)
 * Total Accepted:    248.5K
 * Total Submissions: 724.5K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        if (heights.size() == 1) {
            return heights[0];
        }
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        vector<int> v;
        int maxSize = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!v.empty()) {
                int hI = v.back();
                if (heights[i] >= heights[hI]) {
                    break;
                } else {
                    v.pop_back();
                    maxSize = max(maxSize, heights[hI] * (i - v.back() - 1));
                }
            }
            v.push_back(i);
        }
        return maxSize;
    }
};
