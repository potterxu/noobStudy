#include <string>
using namespace std;

char findTheDifference(string s, string t) {
    char rv = t[t.size() - 1];
    for (int i = 0; i < s.size(); ++i) {
        rv ^= s[i];
        rv ^= t[i];
    }
    return rv;
}