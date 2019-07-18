#include <vector>
#include <algorithm>

using namespace std;

int smallestRangeI(vector<int>& A, int K) {
    auto [min, max] = minmax_element(A.begin(), A.end());
    int rv = *max - *min - K - K;
    return rv > 0 ? rv : 0;
}