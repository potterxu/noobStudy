/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 *
 * https://leetcode.com/problems/divisor-game/description/
 *
 * algorithms
 * Easy (65.97%)
 * Likes:    379
 * Dislikes: 1081
 * Total Accepted:    55.1K
 * Total Submissions: 83.4K
 * Testcase Example:  '2'
 *
 * Alice and Bob take turns playing a game, with Alice starting first.
 * 
 * Initially, there is a number N on the chalkboard.  On each player's turn,
 * that player makes a move consisting of:
 * 
 * 
 * Choosing any x with 0 < x < N and N % x == 0.
 * Replacing the number N on the chalkboard with N - x.
 * 
 * 
 * Also, if a player cannot make a move, they lose the game.
 * 
 * Return True if and only if Alice wins the game, assuming both players play
 * optimally.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: true
 * Explanation: Alice chooses 1, and Bob has no more moves.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: false
 * Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more
 * moves.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 1000
 * 
 * 
 * 
 */

class Solution {
public:
    bool divisorGame(int N) {
        //dp[N] means when the number is N, the operator will always win
        // if exists k that N % k == 0 and dp[N-k] = false (the next one will not win), then dp[N] = true
        //  1 < k < sqrt(N)
        vector<bool> dp(N+1, false);
        dp[0] = false;
        dp[1] = false;
        for (int i = 2; i <= N; ++i) {
            for (int k = 1; k <= sqrt(i); ++k) {
                if (i % k != 0) {
                    continue;
                }
                if (dp[i-k] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
