int hammingDistance(int x, int y) {
    int rv = 0;
    x ^= y;
    while (x != 0) {
        if ((x & 1) != 0) {
            rv++;
        }
        x /= 2;
    }
    return rv;
}