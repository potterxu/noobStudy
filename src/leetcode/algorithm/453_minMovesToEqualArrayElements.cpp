#include <vector>
using namespace std;

int minMoves(vector<int>& nums) {
    long sum = 0;
    int min = 0x7fffffff;
    for (int n : nums) {
        sum += n;
        if (n < min) {
            min = n;
        }
    }
    return sum - min * nums.size();
}