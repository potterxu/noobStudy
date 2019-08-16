#include <string>
using namespace std;

bool repeatedSubstringPattern(string s) {
    for (int i = 1; i <= s.size() / 2; ++i) {
        if (s.size() % i) {
            continue;
        }
        int j = i;
        int k = 0;
        bool ok = true;
        while (j < s.size()) {
            if (s[j] == s[k]) {
                ++j;
                ++k;
                if (k == i) {
                    k -= i;
                } 
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}