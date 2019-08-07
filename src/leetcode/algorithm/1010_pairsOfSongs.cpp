#include <vector>
using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
    int rv = 0;
    int remain[60] {0};
    for (int t : time) {
        int r = t % 60;
        if (r == 0) {
            rv += remain[0];
        } else {
            rv += remain[60 - r];
        }
        ++remain[r];
    }
    return rv;
}