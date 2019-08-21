#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }
    if (haystack.size() < needle.size()) {
        return -1;
    }
    for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
        int ok = true;
        for (int j = 0; j < needle.size(); ++j) {
            if (haystack[i+j] != needle[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return i;
        }
    }
    return -1;
}