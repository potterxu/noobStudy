class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        // maxSum[j] = sumsTo[j] - (min SumsToNums[i] for i < j), so record the minSum before j, so maxSum[j] = sumTo[j] - minSumBefore
        int sum = 0;
        int minSumBefore = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            maxSum = max(maxSum, sum - minSumBefore);
            minSumBefore = min(minSumBefore, sum);
        }
        return maxSum;
    }
};