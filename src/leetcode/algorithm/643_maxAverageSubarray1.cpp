#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }
    int maxSum = sum;
    for (int i = 0; i < nums.size() - k; ++i) {
        sum = sum - nums[i] + nums[k+i];
        maxSum = max(sum, maxSum);
    }
    return double(maxSum) / k;
}