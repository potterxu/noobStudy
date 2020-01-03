class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = -1;
        int sum = 0;
        static int a[] = {10000, 1000, 100, 10, 1};
        for (int i = 0; i < 5; ++i) {
            int digit = n / a[i];
            n %= a[i];
            if (product == -1) {
                if (digit != 0) {
                    product = digit;
                }
            } else {
                product *= digit;
            }
            sum += digit;
        } 
        return product - sum;
    }
};
