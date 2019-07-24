#include <string>
#include <vector>
using namespace std;

string shortestCompletingWord(string licensePlate, vector<string>& words) {
    int lic[26]{0};
    for (char c : licensePlate) {
        c = tolower(c);
        if (c < 'a' || c > 'z') {
            continue;
        }
        lic[c - 'a']++;
    }
    string rv = "";
    for (string w : words) {
        int stat[26]{0};
        for (char c : w) {
            stat[c - 'a']++;
        }
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            if (lic[i] > stat[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (rv.empty()) {
                rv = w;
            } else {
                rv = w.size() < rv.size() ? w : rv;
            }
        }
    }
    return rv;
}