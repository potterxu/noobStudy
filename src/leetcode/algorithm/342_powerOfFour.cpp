bool isPowerOfFour(int num) {
    if (num <= 0) {
        return false;
    } else if (num == 1) {
        return true;
    }
    int mask = 0b01010101010101010101010101010100;
    if (num & mask) {
        num &= num-1;
        if (num == 0) {
            return true;
        }
    }
    return false;
}