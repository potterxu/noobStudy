#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool ok(string &s, unordered_map<string, int> &m) {
    if (s.size() == 1) {
        return true;
    }
    string sub = s.substr(0,s.size() - 1);
    auto it = m.find(sub);
    if (it == m.end()) {
        return false;
    }
    if (it->second == 1) {
        return true;
    } else {
        return ok(sub, m);
    }
}

string longestWord(vector<string>& words) {
    unordered_map<string, int> m;
    int rvI = -1;
    for (string &s : words) {
            m[s] = 0;
    }
    for (int i = 0; i < words.size(); ++i) {
        if (ok(words[i], m)) {
            if (rvI == -1) {
                rvI = i;
            } else {
                if (words[i].size() > words[rvI].size()) {
                    rvI = i;
                } else if (words[i].size() == words[rvI].size()) {
                    if (words[i] < words[rvI]) {
                        rvI = i;
                    }
                }
            }
        }
    }
    return words[rvI];
}