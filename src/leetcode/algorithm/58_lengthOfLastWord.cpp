#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    if (s.empty()) {
        return 0;
    }
    int rv = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ' ') {
            if (rv > 0) {
                return rv;
            }
        } else {
            ++rv;
        }
    }
    return rv;
}