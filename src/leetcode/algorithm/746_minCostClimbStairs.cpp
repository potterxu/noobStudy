#include <vector>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int minCostClimbingStairs(vector<int>& cost) {
    int f1 = cost[0];
    int f2 = cost[1];
    for (int i = 2; i< cost.size(); ++i) {
        int c = cost[i] + min(f1, f2);
        f1 = f2;
        f2 = c;
    }
    return min(f1, f2);
}