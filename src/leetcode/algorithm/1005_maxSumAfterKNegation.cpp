#include <vector>
using namespace std;

int largestSumAfterKNegations(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int rv = 0;
    int minAbs = 0x7fffffff;
    for (int a : A) {
        if (!K) {
            rv += a;
        } else {
            if (a == 0) {
                K = 0;
            } else if (a < 0) {
                rv -= a;
                --K;
                if (-a < minAbs) {
                    minAbs = -a;
                }
            } else {
                if (K&1) {
                    if (a <= minAbs) {
                        rv -= a;
                    } else {
                        rv += a;
                        rv -= minAbs * 2;
                    }
                } else {
                    rv += a;
                }
                K = 0;
            }
        }
    }
    return rv;
}