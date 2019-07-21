#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> uncommonFromSentences(string A, string B) {
    vector<string> rv;
    unordered_map<string, int> m;
    while (!A.empty()) {
        int i = A.find(" ");
        string w;
        if (i == string::npos) {
            w = A;
            A = "";
        } else {
            w = A.substr(0, i);
            A = A.substr(i + 1, A.size() - i - 1);
        }
        if (m.find(w) == m.end()) {
            m[w] = 0;
        }
        m[w]++;
    }
    while (!B.empty()) {
        int i = B.find(" ");
        string w;
        if (i == string::npos) {
            w = B;
            B = "";
        } else {
            w = B.substr(0, i);
            B = B.substr(i + 1, A.size() - i - 1);
        }
        if (m.find(w) == m.end()) {
            m[w] = 0;
        }
        m[w]++;
    }
    for (auto p : m) {
        if (p.second == 1) {
            rv.push_back(p.first);
        }
    }
    return rv;
}