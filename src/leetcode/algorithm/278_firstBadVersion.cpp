bool isBadVersion(int version) {
    return false;
}

int firstBadVersion(int n) {
    if (isBadVersion(1)) {
        return 1;
    }
    if (!isBadVersion(n)) {
        return -1;
    }
    int start = 1;
    int end = n;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isBadVersion(mid)) {
            if (mid - 1 >= 1) {
                if (!isBadVersion(mid - 1)) {
                    return mid;
                }
            }
            end = mid - 1;
        } else {
            if (mid + 1 <= n) {
                if (isBadVersion(mid +1)) {
                    return mid +1;
                }
            }
            start = mid + 1;
        }
    }
    return -1;
}