#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int rv = 0;
    int hold = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
        if (!hold) {
            if (prices[i+1] > prices[i]) {
                hold = 1;
                rv -= prices[i];
            }
        } else {
            if (prices[i+1] < prices[i]) {
                rv += prices[i];
                hold = 0;
            }
        }
    }
    if (hold) {
        rv += prices[prices.size() - 1];
    }
    return rv;
}