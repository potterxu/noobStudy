#include <cmath>
using namespace std;

int arrangeCoins(int n) {
    if (n == 0) {
        return 0;
    }
    int rv = sqrt(long(n) + n);
    if ((long(n)+n) / rv < (rv + 1)) {
        --rv;
    }
    return rv;
}