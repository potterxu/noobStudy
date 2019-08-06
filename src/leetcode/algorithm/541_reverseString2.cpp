#include <string>
using namespace std;

void process(string &s, int index, int k) {
    if (index >= s.size()) {
        return;
    }
    int start = index;
    int end = start + k - 1;
    if (end >= s.size()) {
        end = s.size() - 1;
    }
    while (start < end) {
        swap(s[start], s[end]);
        ++start;
        --end;
    }
    process(s, index + k + k, k);
}

string reverseStr(string s, int k) {
    process(s, 0, k);
    return s;
}