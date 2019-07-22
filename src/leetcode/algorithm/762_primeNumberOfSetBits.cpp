int countPrimeSetBits(int L, int R) {
    int rv = 0;
    int s[21]{0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0};
    for (int i = L; i <= R; ++i) {
        int num = i;
        int ones = 0;
        while (num != 0) {
            num &= num - 1;
            ones++;
        }
        if (s[ones]) {
            rv++;
        }
    }
    return rv;
}