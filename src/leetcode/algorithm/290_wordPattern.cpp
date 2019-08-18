#include <string>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string str) {
    unordered_map<char, string> m;
    unordered_map<string, int> m2;
    int pI = 0;
    string s;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            if (!s.empty()) {
                if (pI >= pattern.size()) {
                    return false;
                }
                if (m[pattern[pI]] == "") {
                    if (m2[s]) {
                        return false;
                    }
                    m[pattern[pI]] = s;
                    m2[s] = 1;
                } else if (m[pattern[pI]] != s) {
                    return false;
                }
                ++pI;
            }
            s = "";
        } else {
            s.push_back(str[i]);
        }
    }
    if (!s.empty()) {
        if (pI >= pattern.size()) {
            return false;
        }
        if (m[pattern[pI]] == "") {
            if (m2[s]) {
                return false;
            }
            m[pattern[pI]] = s;
            m2[s] = 1;
        } else if (m[pattern[pI]] != s) {
            return false;
        }
        ++pI;
    }
    if (pI != pattern.size()) {
        return false;
    }
    return true;
}