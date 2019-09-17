#include <string>
using namespace std;

int count(string &s, int i, int j) {
    if (i < 0 || j >= s.size()) {
        return 0;
    }
    if (s[i] == s[j]) {
        return 1 + count(s, i-1, j+1);
    }
    return 0;
}
int countSubstrings(string s) {
    int rv = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j <= 1; ++j) {
            rv += count(s, i, i+j);
        }
    }
    return rv;
}