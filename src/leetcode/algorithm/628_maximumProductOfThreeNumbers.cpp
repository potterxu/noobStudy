#include <algorithm>
#include <vector>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}
int maximumProduct(vector<int>& nums) {
    int a[6] {1001, 1001, 1001, -1001, -1001, -1001};
    for (int n : nums) {
        if (n < a[0]) {
            swap(n, a[0]);
        }
        if (n < a[1]) {
            swap(n, a[1]);
        }
        if (n < a[2]) {
            swap(n, a[2]);
        }
        if (n != 1001) {
            if (n > a[5]) {
                swap(n, a[5]);
            }
            if (n > a[4]) {
                swap(n, a[4]);
            }
            if (n > a[3]) {
                swap(n, a[3]);
            }
        }
    }
    int rv = -1000000001;
    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            for (int k = j + 1; k < 6; ++k) {
                if (a[i] != 1001 && a[i] != -1001
                    &&a[j] != 1001 && a[j] != -1001
                    &&a[k] != 1001 && a[k] != -1001) {
                    rv = max(rv, a[i]*a[j]*a[k]);
                }
            }
        }
    }
    return rv;
}