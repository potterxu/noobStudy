#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}
void rotate(vector<int>& nums, int k) {
    if (nums.size() <= 1) {
        return;
    }
    k %= nums.size();
    if (!k) {
        return;
    }
    int times = gcd(nums.size(), k);
    for (int n = 0; n < times; ++n) {
        int temp = nums[n];
        int i = n;
        for (int j = 0; j < nums.size() ; ++j) {
            int newI = i + k;
            if (newI >= nums.size()) {
                newI -= nums.size();
            }
            swap(temp, nums[newI]);
            if (newI == n) {
                break;
            }
            i = newI;
        }
    }
}