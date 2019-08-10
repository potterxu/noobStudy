#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> m;
    for (string s : banned) {
        m[s] = -1;
    }
    int i = 0;
    string rv;
    int maxOcc = 0;
    string curS;
    for (char c : paragraph) {
        c = tolower(c);
        if (c < 'a' || c > 'z') {
            if (!curS.empty() && m[curS] > -1) {
                ++m[curS];
                if (m[curS] > maxOcc) {
                    maxOcc = m[curS];
                    rv = curS;
                }
            }
            curS = "";
        } else {
            curS.push_back(c);
        }
    }
    if (!curS.empty()) {
        if (m[curS] > -1) {
            ++m[curS];
            if (m[curS] > maxOcc) {
                maxOcc = m[curS];
                rv = curS;
            }
            curS = "";
        }
    }
    return rv;
}