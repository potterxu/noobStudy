#include <cinttypes>

int hammingWeight(uint32_t n) {
    int rv = 0;
    while (n != 0) {
        n &= (n-1);
        ++rv;
    }
    return rv;
}