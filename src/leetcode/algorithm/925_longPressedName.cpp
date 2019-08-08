#include <string>
using namespace std;

bool isLongPressedName(string name, string typed) {
    int i = 0;
    int j = 0;
    while (i < name.size() && j < typed.size()) {
        if (name[i] == typed[j]) {
            ++i;
            ++j;
        } else {
            if (j == 0) {
                return false;
            } else if (typed[j] != typed[j-1]) {
                return false;
            }
            ++j;
        }
    }
    if (i < name.size()) {
        return false;
    }
    if (j < typed.size()) {
        for (int k = j; k < typed.size(); ++k) {
            if (typed[k] != typed[k-1]) {
                return false;
            }
        }
    }
    return true;
}