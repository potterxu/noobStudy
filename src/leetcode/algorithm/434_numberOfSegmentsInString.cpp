#include <string>
using namespace std;

int countSegments(string s) {
    int rv = 0;
    int count = 0;
    for (char c : s) {
        if (c == ' ') {
            if (count > 0) {
                ++rv;
                count = 0;
            }
        } else {
            ++count;
        }
    }
    if (count > 0) {
        ++rv;
    }
    return rv;
}