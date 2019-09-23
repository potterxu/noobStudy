#include <algorithm>
#include <vector>
using namespace std;

namespace math {
    int uniquePaths(int m, int n) {
        --m;
        --n;
        if (m < n) {
            swap(m, n);
        }
        m = m+n;
        long rv = 1;
        for (int i = 0;i < n; ++i) {
            rv *= (m-i);
        }
        while (n > 1) {
            rv /= n;
            --n;
        }
        return rv;
    }
};

namespace dp {
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    v[i][j] = 1;
                    continue;
                }
                if (i == 0 && j != 0) {
                    v[i][j] += v[i][j-1];
                    continue;
                }
                if (i != 0 && j == 0) {
                    v[i][j] += v[i-1][j];
                    continue;
                }
                v[i][j] += v[i-1][j] + v[i][j-1];
            }
        }
        return v[m-1][n-1];
    }
};