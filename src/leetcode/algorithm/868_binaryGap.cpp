int binaryGap(int N) {
    int rv = 0;
    int preOnePosition = -1;
    int bitPosition = 0;
    while (bitPosition < 32) {
        if ((N & (1 << bitPosition)) != 0) {
            if (preOnePosition == -1) {
                preOnePosition = bitPosition;
            } else{
                int d = bitPosition - preOnePosition;
                preOnePosition = bitPosition;
                rv = d > rv ? d : rv;
            }
        }
        bitPosition++;
    }
    return rv;
}