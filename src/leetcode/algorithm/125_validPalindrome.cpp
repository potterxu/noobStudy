#include <string>
using namespace std;

bool isAlphanumeric(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}
bool isPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
        s[start] = tolower(s[start]);
        s[end] = tolower(s[end]);
        if (!isAlphanumeric(s[start])) {
            ++start;
            continue;
        }
        if (!isAlphanumeric(s[end])) {
            --end;
            continue;
        }
        if (s[start] != s[end]) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}