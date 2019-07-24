#include <string>
using namespace std;

bool isChar(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    if (c >= 'A' && c<= 'Z') {
        return true;
    }
    return false;
}
string reverseOnlyLetters(string S) {
    int i = 0;
    int j = S.size() - 1;
    while (i < j) {
        if (!isChar(S[i])) {
            ++i;
        }
        if (!isChar(S[j])) {
            --j;
        }
        if (isChar(S[i]) && isChar(S[j])) {
            swap(S[i], S[j]);
            ++i;
            --j;
        }
    }
    return S;
}