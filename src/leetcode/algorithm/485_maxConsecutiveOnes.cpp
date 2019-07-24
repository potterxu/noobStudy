#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0;
    int cur = 0;
    for (int n : nums) {
        if (n == 1) {
            ++cur;
        } else {
            max = cur > max ? cur : max;
            cur = 0;
        }
    }
    max = cur > max ? cur : max;
    return max;
}