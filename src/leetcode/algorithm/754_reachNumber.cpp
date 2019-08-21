int reachNumber(int target) {
    if (target < 0) {
        target = -target;
    }
    int rv = 0;
    while (target > 0) {
        ++rv;
        target -= rv;
    }
    target = -target;
    while (target&1) {
        ++rv;
        target += rv;
    }
    return rv;
}