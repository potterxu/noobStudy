#include <string>
#include <vector>
using namespace std;

string horizontalScan(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    } else if (strs.size() == 1) {
        return strs[0];
    }
    int ptr = 0;
    int size = strs[0].size();
    for (int i = 1; i < strs.size(); ++i) {
        string &s = strs[i];
        while (ptr < size && ptr < s.size()) {
            if (strs[0][ptr] == s[ptr]) {
                ++ptr;
            } else {
                break;
            }
        }
        if (ptr == 0) {
            return "";
        }
        size = ptr;
        ptr = 0;
    }
    return strs[0].substr(0, size);
}
string verticalScan(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    } else if (strs.size() == 1) {
        return strs[0];
    }
    string rv;
    for (int c = 0; c < strs[0].size(); ++c) {
        bool ok = true;
        int r = 0;
        for (int r = 0; r < strs.size() - 1; ++r) {
            if (c >= strs[r].size() || c >= strs[r+1].size()) {
                ok = false;
                break;
            }
            if (strs[r][c] != strs[r+1][c]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            rv.push_back(strs[0][c]);
        } else {
            break;
        }
    }
    return rv;
}