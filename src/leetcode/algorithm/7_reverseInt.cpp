int reverse(int x) {
    bool neg = false;
    if (x == 0x80000000) {
        return 0;
    }
    if (x < 0) {
        neg = true;
        x = -x;
    }
    int rv = 0;
    while (x > 0) {
        if (rv > 0x7fffffff / 10) {
            return 0;
        }
        rv *= 10;
        rv += x % 10;
        x /= 10;
    }
    if (neg) {
        rv = -rv;
    }
    return rv;
}