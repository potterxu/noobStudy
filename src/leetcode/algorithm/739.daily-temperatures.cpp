/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (62.73%)
 * Likes:    2639
 * Dislikes: 82
 * Total Accepted:    150.9K
 * Total Submissions: 240.3K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> rv(T.size(), 0);
        if (T.size() < 2) {
            return rv;
        }
        stack<int> decreasingStack; //store the pos of temp
        for (int i = 0; i < T.size(); ++i) {
            if (decreasingStack.empty()) {
                decreasingStack.push(i);
            } else {
                while (!decreasingStack.empty()) {
                    if (T[i] > T[decreasingStack.top()]) {
                        rv[decreasingStack.top()] = i - decreasingStack.top();
                        decreasingStack.pop();
                    } else {
                        break;
                    }
                }
                decreasingStack.push(i);
            }
        }
        while (!decreasingStack.empty()) {
            rv[decreasingStack.top()] = 0;
            decreasingStack.pop();
        }
        return rv;
    }
};
// @lc code=end
