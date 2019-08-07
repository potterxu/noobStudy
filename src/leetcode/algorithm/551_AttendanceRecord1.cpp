#include <string>
using namespace std;

bool checkRecord(string s) {
    int absent = 0;
    int late = 0;
    for (char c : s) {
        if (c == 'L') {
            if (late == 2) {
                return false;
            }
            ++late;
        } else {
            late = 0;
            if (c == 'A') {
                if (absent) {
                    return false;
                }
                ++absent;
            }
        }
    }
    return true;
}