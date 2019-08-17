int trailingZeroes(int n) {
    int rv = 0;
    for (long i = 5; i <= n; i*=5) {
        rv += n / i;
        if (i * 5 > n) {
            break;
        }
    }
    return rv;
}