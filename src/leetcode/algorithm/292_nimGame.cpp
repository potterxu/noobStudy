bool canWinNim(int n) {
    if ((n & 3) == 0) {
        return false;
    }
    return true;
}