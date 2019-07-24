#include <string>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}
int countBinarySubstrings(string s) {
    int pre = 0, cur = 1, rv = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
            ++cur;
        } else {
            rv += min(pre, cur);
            pre = cur;
            cur = 1;
        }
    }
    return rv + min(pre, cur);
}