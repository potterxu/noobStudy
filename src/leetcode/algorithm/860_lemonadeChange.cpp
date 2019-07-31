#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int c[3]{0};
    for (int b : bills) {
        if (b == 5) {
            ++c[0];
        } else if (b == 10) {
            if (c[0] < 1) {
                return false;
            }
            --c[0];
            ++c[1];
        } else if (b == 20) {
            if (c[1] > 0) {
                --c[1];
                if (c[0] < 1) {
                    return false;
                }
                --c[0];
                ++c[2];
            } else {
                if (c[0] < 3) {
                    return false;
                }
                c[0] -= 3;
                ++ c[2];
            }
        }
    }
    return true;
}