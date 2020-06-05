/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 *
 * https://leetcode.com/problems/champagne-tower/description/
 *
 * algorithms
 * Medium (35.34%)
 * Likes:    390
 * Dislikes: 23
 * Total Accepted:    13.7K
 * Total Submissions: 38.9K
 * Testcase Example:  '1\n1\n1'
 *
 * We stack glasses in a pyramid, where the first row has 1 glass, the second
 * row has 2 glasses, and so on until the 100th row.  Each glass holds one cup
 * (250ml) of champagne.
 * 
 * Then, some champagne is poured in the first glass at the top.  When the top
 * most glass is full, any excess liquid poured will fall equally to the glass
 * immediately to the left and right of it.  When those glasses become full,
 * any excess champagne will fall equally to the left and right of those
 * glasses, and so on.  (A glass at the bottom row has it's excess champagne
 * fall on the floor.)
 * 
 * For example, after one cup of champagne is poured, the top most glass is
 * full.  After two cups of champagne are poured, the two glasses on the second
 * row are half full.  After three cups of champagne are poured, those two cups
 * become full - there are 3 full glasses total now.  After four cups of
 * champagne are poured, the third row has the middle glass half full, and the
 * two outside glasses are a quarter full, as pictured below.
 * 
 * 
 * 
 * Now after pouring some non-negative integer cups of champagne, return how
 * full the j-th glass in the i-th row is (both i and j are 0 indexed.)
 * 
 * 
 * 
 * 
 * Example 1:
 * Input: poured = 1, query_glass = 1, query_row = 1
 * Output: 0.0
 * Explanation: We poured 1 cup of champange to the top glass of the tower
 * (which is indexed as (0, 0)). There will be no excess liquid so all the
 * glasses under the top glass will remain empty.
 * 
 * Example 2:
 * Input: poured = 2, query_glass = 1, query_row = 1
 * Output: 0.5
 * Explanation: We poured 2 cups of champange to the top glass of the tower
 * (which is indexed as (0, 0)). There is one cup of excess liquid. The glass
 * indexed as (1, 0) and the glass indexed as (1, 1) will share the excess
 * liquid equally, and each will get half cup of champange.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * poured will be in the range of [0, 10 ^ 9].
 * query_glass and query_row will be in the range of [0, 99].
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) {
            return 0.0;
        }
        if (query_glass > query_row) {
            // no such glass exist
            return 0.0;
        }
        // f(i,j) is the totol champagne poured to cup[i][j]
        // dp: f(i,j) = 1/2 (f(i, j-1) + f(i-1, j-1) - 2)
        vector<double> champagneInCup = {static_cast<double>(poured)};
        while (champagneInCup.size() < query_row+1) {
            if (champagneInCup.back() > 1.0) {
                champagneInCup.push_back((champagneInCup.back() - 1.0) / 2);
            } else {
                champagneInCup.push_back(0.0);
            }
            for (int i = champagneInCup.size() - 2; i >= 0; --i) {
                if (champagneInCup[i] > 1.0) {
                    champagneInCup[i] -= 1.0;
                } else {
                    champagneInCup[i] = 0.0;
                }
                if (i >= 1 && champagneInCup[i-1] > 1.0) {
                    champagneInCup[i] += champagneInCup[i-1] - 1.0;
                }
                 champagneInCup[i] /= 2.0;
                
            }
            // the middle one contains most champagne
            if (champagneInCup[champagneInCup.size()/2] <= 1.0) {
                // no wine go to next row
                break;
            }
        }
        if (champagneInCup.size() <= query_row) {
            return 0.0;
        }
        return min(1.0, champagneInCup[query_glass]);
    }
};
// @lc code=end
