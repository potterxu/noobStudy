    bool hasAlternatingBits(int n) {
        int full = 1;
        while (full < n) {
            full += full + 1;
        }
        if ((n ^ (n / 2)) == full) {
            return true;
        } else {
            return false;
        }
    }