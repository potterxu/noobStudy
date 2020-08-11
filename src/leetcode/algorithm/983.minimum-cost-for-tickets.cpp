/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 *
 * https://leetcode.com/problems/minimum-cost-for-tickets/description/
 *
 * algorithms
 * Medium (59.43%)
 * Likes:    1570
 * Dislikes: 32
 * Total Accepted:    51.6K
 * Total Submissions: 85.4K
 * Testcase Example:  '[1,4,6,7,8,20]\n[2,7,15]'
 *
 * In a country popular for train travel, you have planned some train
 * travelling one year in advance.  The days of the year that you will travel
 * is given as an array days.  Each day is an integer from 1 to 365.
 * 
 * Train tickets are sold in 3 different ways:
 * 
 * 
 * a 1-day pass is sold for costs[0] dollars;
 * a 7-day pass is sold for costs[1] dollars;
 * a 30-day pass is sold for costs[2] dollars.
 * 
 * 
 * The passes allow that many days of consecutive travel.  For example, if we
 * get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6,
 * 7, and 8.
 * 
 * Return the minimum number of dollars you need to travel every day in the
 * given list of days.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: days = [1,4,6,7,8,20], costs = [2,7,15]
 * Output: 11
 * Explanation: 
 * For example, here is one way to buy passes that lets you travel your travel
 * plan:
 * On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
 * On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3,
 * 4, ..., 9.
 * On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
 * In total you spent $11 and covered all the days of your travel.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * Output: 17
 * Explanation: 
 * For example, here is one way to buy passes that lets you travel your travel
 * plan:
 * On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1,
 * 2, ..., 30.
 * On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
 * In total you spent $17 and covered all the days of your travel.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days is in strictly increasing order.
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 * 
 * 
 */

class Solution {
public:
    int findDaysAfter(vector<int>& days, int start, int day) {
        // find first index that > than day
        int end = days.size()-1;
        if (day > days[end]) {
            return end+1;
        }
        if (day < days[start]) {
            return start;
        }
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (day >= days[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end+1;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> minCost(days.size());
        minCost.back() = min(costs[0], costs[1]);
        minCost.back() = min(minCost.back(), costs[2]);
        for (int i = days.size() - 2; i >= 0; --i) {
            int nextD = i + 1;
            int cost1 = costs[0] + minCost[nextD];

            int cost7 = costs[1];
            nextD = findDaysAfter(days, i+1, days[i] + 6);
            if (nextD < days.size()) {
                cost7 += minCost[nextD];
            }
            int cost30 = costs[2];
            nextD = findDaysAfter(days, i+1, days[i] + 29);
            if (nextD < days.size()) {
                cost30 += minCost[nextD];
            }
            minCost[i] = min(cost1, cost7);
            minCost[i] = min(minCost[i], cost30);
            //printf("%d, %d, %d, %d, %d\n", days[i], cost1, cost7, cost30, minCost[i]);
        }
        return minCost[0];
    }
};
