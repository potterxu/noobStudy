#include <string>
using namespace std;

bool isPalindrome(string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}
bool validPalindrome(string s) {
    if (s.empty()) {
        return false;
    }
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
        if (s[start] != s[end]) {
            if (start < end - 1) {
                return isPalindrome(s, start, end - 1) || isPalindrome(s, start + 1, end); 
            }
        }
        ++start;
        --end;
    }
    return true;
}