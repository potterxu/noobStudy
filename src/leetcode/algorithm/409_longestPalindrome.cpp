#include <string>
using namespace std;

int longestPalindrome(string s) {
    int a[52] {0};
    for (char c : s) {
        int index = 0;
        if (c < 'a') {
            index = c - 'A' + 26;
        } else {
            index = c - 'a';
        }
        ++a[index];
    }
    int rv = 0;
    for (int i = 0; i < 52; ++i) {
        if (a[i] & 1) {
            if (!(rv&1)) {
                rv += a[i];
            } else {
                rv += a[i] - 1;
            }
        } else {
            rv += a[i];
        }
    }
    return rv;
} 