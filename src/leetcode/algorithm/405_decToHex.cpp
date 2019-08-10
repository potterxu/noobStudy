#include <string>
using namespace std;

string toHex(int num) {
    string rv;
    if (num < 0) {
        num = 0xffffffff + num + 1;
    }
    if (num > 0) {
        while (num != 0) {
            char remain = num & 0xf;
            if (remain < 10) {
                rv.push_back(remain + 48);
            } else {
                rv.push_back(remain + 87);
            }
            num /= 16;
        }
        reverse(rv.begin(), rv.end());
    } else if (num == 0) {
        rv = "0";
    } else {
        rv = "ffffffff";
        num = -num - 1;
        int i = 7;
        while (num != 0) {
            char remain = num & 0xf;
            remain = rv[i] - 87 - remain;
            if (remain < 10) {
                rv[i] = remain + 48;
            } else {
                rv[i] = remain + 87;
            }
            num /= 16;
            --i;
        }
    }
    return rv;
}