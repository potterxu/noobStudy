#include <cmath>
using namespace std;

static const int max = pow(3, 19);
bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }
    return (max % n) == 0;
}