#include <string>
using namespace std;

int firstUniqChar(string s) {
    int a[26];
     for (int i = 0; i < 26; ++i) {
        a[i] = -1;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (a[s[i] - 'a'] == -2) {
            continue;
        } else if (a[s[i] - 'a'] == -1) {
            a[s[i] - 'a'] = i;
        } else {
            a[s[i] - 'a'] = -2;
        }
    }
    int rv = s.size();
    for (int i = 0; i < 26; ++i) {
        if (a[i] >= 0) {
            rv = a[i] < rv ? a[i] : rv;
        }
    }
    return rv == s.size() ? -1 : rv;
}