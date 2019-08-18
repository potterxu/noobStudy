#include <cmath>
using namespace std;

bool checkPerfectNumber(int num) {
    if (num <= 1) {
        return false;
    }
    int sq = sqrt(num);
    int sum = 1;
    while (sq > 1) {
        if (num % sq) {
            --sq;
            continue;
        }
        sum += sq;
        int t = num / sq;
        if (sq != t) {
            sum += t;
        }
        --sq;
    }
    if (num == sum) {
        return true;
    }
    return false;;
}