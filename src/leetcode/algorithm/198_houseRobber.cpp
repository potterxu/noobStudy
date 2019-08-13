#include <vector>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int rob(vector<int>& nums) {
    int f1 = 0;
    int f2 = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i&1) {
            f2 = max(f1, f2 + nums[i]);
        } else {
            f1 = max(f2, f1 + nums[i]);
        }
    }
    return max(f1, f2);
}