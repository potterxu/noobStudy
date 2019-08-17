bool isPerfectSquare(int num) {
    int square = 1;
    int i = 1;
    while (square <= num) {
        if (square == num) {
            return true;
        }
        if (square > 0x7fffffff - i - i - 1) {
            break;
        }
        square += i + i + 1;
        ++i;
    }
    return false;
}