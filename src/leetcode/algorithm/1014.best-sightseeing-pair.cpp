/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 *
 * https://leetcode.com/problems/best-sightseeing-pair/description/
 *
 * algorithms
 * Medium (51.99%)
 * Likes:    424
 * Dislikes: 22
 * Total Accepted:    16.1K
 * Total Submissions: 30.9K
 * Testcase Example:  '[8,1,5,2,6]'
 *
 * Given an array A of positive integers, A[i] represents the value of the i-th
 * sightseeing spot, and two sightseeing spots i and j have distance j - i
 * between them.
 * 
 * The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) :
 * the sum of the values of the sightseeing spots, minus the distance between
 * them.
 * 
 * Return the maximum score of a pair of sightseeing spots.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [8,1,5,2,6]
 * Output: 11
 * Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 50000
 * 1 <= A[i] <= 1000
 * 
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int rv = INT_MIN;
        int startMaxScore = -1;
        int endScore = -1;
        for (int i = 0; i < A.size() - 1; ++i) {
            startMaxScore = max(startMaxScore, A[i] + i);
            endScore = A[i+1] - i - 1;
            rv = max(startMaxScore+endScore, rv);
        }
        return rv;
    }
};
// @lc code=end
