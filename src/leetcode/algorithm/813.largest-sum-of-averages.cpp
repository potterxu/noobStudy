/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 *
 * https://leetcode.com/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (49.25%)
 * Likes:    938
 * Dislikes: 45
 * Total Accepted:    24.8K
 * Total Submissions: 49.7K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * We partition a row of numbers A into at most K adjacent (non-empty) groups,
 * then our score is the sum of the average of each group. What is the largest
 * score we can achieve?
 * 
 * Note that our partition must use every number in A, and that scores are not
 * necessarily integers.
 * 
 * 
 * Example:
 * Input: 
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation: 
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9
 * + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
 * 
 * 
 */

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if (A.size() == 1) {
            return A[0];
        }
        // A change to preSum
        vector<double> sum(A.size(), 0.0);
        vector<double> dp(A.size(), 0.0);
        dp[0] = A[0];
        sum[0] = A[0];
        for (int i = 1; i < A.size(); ++i) {
            sum[i] = sum[i-1] + A[i];
            dp[i] = sum[i] / (i+1);
        }
        // now dp stores max average sum by divide [0,i] to 1 part
        for (int k = 2; k <= K; ++k) {
            for (int i = dp.size()-1; i >= k-1; --i) {
                // to divide [0,i] to k part, at least k elements needed, which means i + 1 == k
                double maxAverageSum = 0;
                for (int j = k-2; j < i; ++j) {
                    // divide [0, j] to k-1 part and [j+1, i] to 1 part
                    maxAverageSum = max(maxAverageSum, dp[j] + (sum[i]-sum[j])/(i-j));
                }
                dp[i] = maxAverageSum;
            }
        }
        return dp.back();
    }
};
