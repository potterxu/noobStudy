class Solution {
public:
    int tribonacci(int n) {
        int a[3] = {0, 1, 1};
        if (n < 3) {
            return a[n];
        }
        int rv = 0;
        int index = 0;
        for (int i = 3; i<=n; ++i) {
            if (index == 3) {
                index = 0;
            }
            int sum = 0;
            for (int j = 0; j < 3; ++j) {
                sum += a[j];
            }
            a[index] = sum;
            rv = sum;
            ++index;
        }
        return rv;
    }
};
