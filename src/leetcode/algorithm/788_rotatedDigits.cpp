#include <string>
using namespace std;

int rotatedDigits(int N) {
    int a[10] {1, 1, 2, 0, 0, 2, 2, 0, 1, 2};
    int rv = 0;
    for (int i = 0; i < N + 1; ++i) {
        string s = to_string(i);
        bool noLabelZero = true;
        bool hasLabelTwo = false;
        for (char c : s) {
            if (a[c - '0'] == 0) {
                noLabelZero = false;
                break;
            } else if (a[c - '0'] == 2) {
                hasLabelTwo = true;
            }
        }
        if (noLabelZero && hasLabelTwo) {
            ++rv;
        }
    }
    return rv;
}