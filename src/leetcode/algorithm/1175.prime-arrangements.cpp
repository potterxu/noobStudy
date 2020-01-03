class Solution {
public:
    int numPrimeArrangements(int n) {
        static vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        int index = 0;
        while (index < primes.size()) {
            if (primes[index] > n) {
                break;
            }
            ++index;
        }
        long rv = 1;
        for (int i = 2; i <= max(index, n-index); ++i) {
            if (i <= min(index, n-index)) {
                rv *= i*i;
            } else {
                rv *= i;
            }
            if (rv >= 1000000007) {
                rv %= 1000000007;
            }
        }
        return rv;
    }
};
