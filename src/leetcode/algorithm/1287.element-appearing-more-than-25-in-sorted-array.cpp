/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		int countNeed = (arr.size() + 4) / 4;
		int rv = -1;
		for (int i = 0; i < arr.size(); ++i) {
			if (i >= 1 && arr[i] == arr[i-1]) {
				continue;
			}
			if (arr[i] == arr[i+countNeed-1]) {
				rv = arr[i];
				break;
			}
		}
		return rv;
	}
};
// @lc code=end
