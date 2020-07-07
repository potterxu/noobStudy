/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (48.94%)
 * Likes:    1208
 * Dislikes: 46
 * Total Accepted:    60.8K
 * Total Submissions: 123.9K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays A and B, return the maximum length of an subarray
 * that appears in both arrays.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation: 
 * The repeated subarray with maximum length is [3, 2, 1].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    int dp(vector<int> &A, vector<int> &B) {
        // f[i][j] = common array size start from A[i] and B[j]
        // f[i][j] = A[i] == B[j] ? f[i+1][j+1] + 1 : 0
        if (A.empty() || B.empty()) {
            return 0;
        }
        vector<vector<int> > v(A.size(), vector<int>(B.size()));
        int rv = 0;
        for (int i = A.size() - 1; i > -1; --i) {
            for (int j = B.size() - 1; j > -1; --j) {
                if (A[i] != B[j]) {
                    v[i][j] = 0;
                } else {
                    if (i+1 < A.size() && j+1 < B.size()) {
                        v[i][j] = v[i+1][j+1] + 1;
                    } else {
                        v[i][j] = 1;
                    }
                }
                rv = max(rv, v[i][j]);
            }
        }
        return rv;
    }

    int slidingWindow(vector<int> &A, vector<int>& B) {
        int rv = 0;
        for (int i = 0; i < A.size(); ++i) {
            int length = 0;
            for (int j = 0; j < B.size() && i + j < A.size(); ++j) {
                if (A[i+j] == B[j]) {
                    ++length;
                } else {
                    rv = max(length, rv);
                    length = 0;
                }
            }
            rv = max(length, rv);
        }
        return rv;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        //int rv = slidingWindow(A, B);
        //rv = max(rv, slidingWindow(B, A));
        //return rv;
        return dp(A, B);
    }
};
