int bitwiseComplement(int N) {
    int a = 1;
    while (a < N) {
        a += a + 1;
    }
    return a - N;
}