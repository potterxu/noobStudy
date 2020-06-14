/*
 * @lc app=leetcode id=1300 lang=cpp
 *
 * [1300] Sum of Mutated Array Closest to Target
 *
 * https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/
 *
 * algorithms
 * Medium (45.84%)
 * Likes:    200
 * Dislikes: 32
 * Total Accepted:    8.3K
 * Total Submissions: 18.1K
 * Testcase Example:  '[4,9,3]\n10'
 *
 * Given an integer array arr and a target value target, return the integer
 * value such that when we change all the integers larger than value in the
 * given array to be equal to value, the sum of the array gets as close as
 * possible (in absolute difference) to target.
 * 
 * In case of a tie, return the minimum such integer.
 * 
 * Notice that the answer is not neccesarilly a number from arr.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,9,3], target = 10
 * Output: 3
 * Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's
 * the optimal answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,3,5], target = 10
 * Output: 5
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [60864,25176,27249,21296,20204], target = 56803
 * Output: 11361
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i], target <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        arr.push_back(0);
        sort(arr.begin(), arr.end());
        vector<int> presum = arr;
        for (int i = 1; i < arr.size(); ++i) {
            presum[i] += presum[i-1];
        }
        if (presum.back() <= target) {
            return arr.back();
        }
        int cur = 0;
        int next = 1; // find the [cur, next] that has the target sum inside
        while (cur < arr.size()) {
            while (next < arr.size()) {
                if (arr[next] != arr[cur]) {
                    break;
                }
                ++next;
            }
            cur = next - 1;
            int minSum = presum[cur] + arr[cur] * (arr.size() - 1 - cur);
            int maxSum = presum[cur] + arr[next] * (arr.size() - 1 - cur);
            if (minSum <= target && maxSum >= target) {
                break;
            }
            cur = next;
        }
        int start = arr[cur];
        int end = arr[next];
        while (start < end) {
            int startSum = presum[cur] + start * (arr.size() - 1 - cur);
            int endSum = presum[cur] + end * (arr.size() - 1 - cur);
            //printf("%d, %d\n", startSum, nextSum);
            if (startSum == target) {
                return start;
            } else if (endSum == target) {
                return end;
            }
            int mid = (start + end) / 2;
            int midSum = presum[cur] + mid * (arr.size() - 1 - cur);
            if (midSum == target) {
                return mid;
            } else if (midSum > target) {
                if (mid-1 <= start) {
                    end = start + 1;
                    break;
                }
                end = mid;
            } else {
                if (mid+1 >= end) {
                    start = end - 1;
                    break;
                }
                start = mid;
            }
            //if (nextSum >= target) {
            //    int startDiff = target - startSum;
            //    int nextDiff = nextSum - target;
            //    if (startDiff <= nextDiff) {
            //        break;
            //    } else {
            //        start++;
            //        break;
            //    }
            //}
            //++start;
        }
        int startSum = presum[cur] + start * (arr.size() - 1 - cur);
        int endSum = presum[cur] + end * (arr.size() - 1 - cur);
        int startDiff = target - startSum;
        int endDiff = endSum - target;
        //printf("%d,%d,%d,%d,%d,%d\n", start, end, startSum, endSum,startDiff,endDiff);
        if (startDiff <= endDiff) {
            return start;
        }
        return end;
    }
};
// @lc code=end
