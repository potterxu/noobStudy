int getSum(int a, int b) {
    if (b == 0) {
        return a;
    }
    unsigned int And = a & b;
    int Xor = a ^ b;
    return getSum(Xor, And * 2);
}