#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int min = 0x7fffffff;
    int rv = 0;
    for (int i = 0; i< prices.size() - 1; ++i) {
        if (prices[i] < prices[i+1]) {
            if (prices[i] < min) {
                min = prices[i];
            }
        } if (prices[i] > prices[i+1]) {
            if (prices[i] - min > rv) {
                rv = prices[i] - min;
            }
        }
    }
    int d = prices[prices.size() - 1] - min;
    if (d > rv) {
        rv = d;
    }
    return rv;
}