#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> m;
    unordered_map<char, int> m2;
    bool rv = true;
    for (int i = 0; i < s.size(); ++i) {
        if (m[s[i]] == 0) {
            m[s[i]] = t[i];
            if (m2[t[i]] != 0) {
                return false;
            }
            m2[t[i]] = 1;
        } else {
            if (m[s[i]] != t[i]) {
                return false;
            }
        }
    }
    return rv;
}