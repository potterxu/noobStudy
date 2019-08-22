#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n > (flowerbed.size() + 1) / 2) {
        return false;
    }
    int count = 1;
    for (int f : flowerbed) {
        if (f) {
            n -= (count - 1) / 2;
            if (n <= 0) {
                return true;
            }
            count = 0;
        } else {
            ++count;
        }
    }
    ++count;
    n -= (count - 1) / 2;
    if (n <= 0) {
        return true;
    }
    return false;
}