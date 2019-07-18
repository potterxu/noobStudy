#include <string>

using namespace std;

void reverse(string &s, int start, int end) {
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}
string reverseWords(string s) {
    int wStart = 0, wEnd = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            wEnd = i - 1;
            reverse(s, wStart, wEnd);
            wStart = i + 1;
        }
    }
    reverse(s, wStart, s.size() - 1);
    return s;
}