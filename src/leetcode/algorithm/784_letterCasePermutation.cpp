#include <string>
#include <vector>
using namespace std;

bool isChar(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

char toggle(char c) {
    return c >= 'a' ? c - 0x20 : c + 0x20;
}

vector<string> letterCasePermutation(string S) {
    vector<string> rv;
    if (S.empty()) {
        return rv;
    }

    vector<string> vec = letterCasePermutation(S.substr(0, S.size() - 1));
    if (vec.empty()) {
        string s;
        s.push_back(S[S.size() - 1]);
        rv.push_back(s);
        if (isChar(S[S.size() - 1])) {
            s = "";
            s.push_back(toggle(S[S.size() - 1]));
            rv.push_back(s);
        }
    } else {
        for (string str : vec) {
            string s = str;
            s.push_back(S[S.size() - 1]);
            rv.push_back(s);
            if (isChar(S[S.size() - 1])) {
                s = str;
                s.push_back(toggle(S[S.size() - 1]));
                rv.push_back(s);
            }
        }
    }
    return rv;
}