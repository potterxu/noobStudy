#include <string>
using namespace std;

int romanToInt(char c) {
    if (c == 'I') {
        return 1;
    }
    if (c == 'V') {
        return 5;
    }
    if (c == 'X') {
        return 10;
    }
    if (c == 'L') {
        return 50;
    }
    if (c == 'C') {
        return 100;
    }
    if (c == 'D') {
        return 500;
    }
    return 1000;
}
int romanToInt(string s) {
    int rv = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
        int tmp = romanToInt(s[i]);
        if (tmp < romanToInt(s[i+1])) {
            rv -= tmp;
        } else {
            rv += tmp;
        }
    }
    rv += romanToInt(s[s.size() - 1]);
    return rv;
}