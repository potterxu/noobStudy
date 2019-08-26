#include <vector>
using namespace std;

int countPrimes(int n) {
    if (n < 3) {
        return 0;
    }
    vector<bool> v(n, true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (!v[i]) {
            continue;
        }
        for (int j = i * i; j <= n; j+=i) {
            v[j] = false;
        }
    }
    int rv = 0;
    for (bool b : v) {
        if (b) {
            ++rv;
        }
    }
    return rv;
}