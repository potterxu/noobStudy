#include <string>
using namespace std;

bool isVowel(char c) {
    switch (tolower(c)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}
string reverseVowels(string s) {
    if (s.size() <= 1) {
        return s;
    }
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
        if (!isVowel(s[start])) {
            ++start;
            continue;
        }
        if (!isVowel(s[end])) {
            --end;
            continue;
        }
        swap(s[start], s[end]);
        ++start;
        --end;
    }
    return s;
}