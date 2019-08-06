#include <deque>
#include <string>
using namespace std;

bool backspaceCompare(string S, string T) {
    deque<char> q;
    for (char c : S) {
        if (c == '#') {
            if (!q.empty()) {
                q.pop_back();
            }
        } else {
            q.push_back(c);
        }
    }
    int i = T.size() - 1;
    int backspace = 0;
    while (i > -1) {
        if (T[i] == '#') {
            ++backspace;
        } else {
            if (backspace > 0) {
                --backspace;
                --i;
                continue;
            }
            if (i < 0) {
                break;
            }
            if (!q.empty()) {
                if (T[i] != q.back()) {
                    return false;
                }
                q.pop_back();
            }
        }
        --i;
    }
    if (i > -1 || !q.empty()) {
        return false;
    }
    return true;
}