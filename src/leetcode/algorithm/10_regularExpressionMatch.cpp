#include <string>
using namespace std;

namespace recursive
{
bool r(string &s, int si, string &p, int pi) {
    if (pi >= p.size()) {
        if (si >= s.size()) {
            return true;
        } else {
            return false;
        }
    }
    bool curMatch = false;
    if (si < s.size()) {
        curMatch = p[pi] == '.' || s[si] == p[pi];
    }
    if (pi == p.size() - 1) {
        return curMatch && r(s,si+1, p, pi+1);
    }
    if (p[pi+1] != '*') {
        return curMatch && r(s,si+1, p, pi+1);
    }
    return (curMatch && r(s, si+1, p, pi)) || r(s, si, p, pi+2);
}
bool isMatch(string s, string p) {
    return r(s, 0, p, 0);
}
};