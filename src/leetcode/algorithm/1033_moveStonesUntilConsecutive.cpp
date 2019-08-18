#include <vector>
using namespace std;

vector<int> numMovesStones(int a, int b, int c) {
    vector<int> rv(2);
    if (a > b) {
        swap(a, b);
    }
    if (a > c) {
        swap(a, c);
    }
    if (b > c) {
        swap (b, c);
    }
    if (b - a == 1 && c - b == 1) {
        rv[0] = 0;
    } else if (b - a <= 2 || c - b <= 2) {
        rv[0] = 1;
    } else {
        rv[0] = 2;
    }
    rv[1] = c - b - 1 + b - a - 1;
    return rv;
}