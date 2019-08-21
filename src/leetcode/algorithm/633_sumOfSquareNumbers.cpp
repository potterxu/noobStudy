#include <cmath>
using namespace std;

bool judgeSquareSum(int c) {
    for (int a = 0; a <= sqrt(c); ++a) {
        int sqrtB = sqrt(c - a*a);
        if (c - a*a == sqrtB * sqrtB) {
            return true;
        }
    }
    return false;
}