#include <unordered_map>
#include <vector>
using namespace std;

vector<int> powerfulIntegers(int x, int y, int bound) {
    vector<int> rv;
    unordered_map<int, int> m;
    int powX = 0;
    int valX = 1;
    while (valX <= bound) {
        int powY = 0;
        int valY = 1;
        while (valY <= bound - valX) {
            int v = valX + valY;
            if (m[v] == 0) {
                rv.push_back(v);
                m[v] = 1;
            }
            if (y == 1) {
                break;
            }
            ++powY;
            valY = pow(y, powY);
        }
        if (x == 1) {
            break;
        }
        ++powX;
        valX = pow(x, powX);
    }
    return rv;
}