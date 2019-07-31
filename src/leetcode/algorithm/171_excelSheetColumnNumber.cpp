#include <string>
#include <cmath>
using namespace std;

int titleToNumber(string s) {
    int rv = 0;
    int power = 0;
    for (int i = s.size() - 1; i > -1; --i) {
        rv += (s[i] - 'A' + 1) * pow(26, power);
        ++power;
    }
    return rv;
}