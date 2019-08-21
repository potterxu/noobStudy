#include <vector>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    static vector<uint32_t> ar = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x800000, 0x1000000, 0x2000000, 0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000};
    for (int i = 0; i < 16; ++i) {
        uint32_t a = n&ar[i];
        uint32_t b = n&ar[31-i];
        if (a) {
            n |= ar[31-i];
        } else {
            n &= (0xffffffff - ar[31-i]);
        }
        if (b) {
            n |= ar[i];
        } else {
            n &= (0xffffffff - ar[i]);
        }
    }
    return n;
}