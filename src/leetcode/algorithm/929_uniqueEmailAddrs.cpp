#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int numUniqueEmails(vector<string>& emails) {
    int rv = 0;
    unordered_map<string, unordered_map<string,int>> m;
    for (string str : emails) {
        string local, domain;
        bool getLocal = true;
        bool getDomain = false;
        for (char c : str) {
            if (c == '@') {
                getLocal = false;
                getDomain = true;
            }
            if (getLocal) {
                if (c == '+') {
                    getLocal = false;
                } else if (c != '.') {
                    local += c;
                }
            }
            if (getDomain) {
                domain += c;
            }
        }
        if (m.find(local) == m.end()) {
            unordered_map<string, int> tmp = {{domain, 1}};
            m[local] = tmp;
            rv++;
        } else {
            if (m[local].find(domain) == m[local].end()) {
                m[local][domain] = 1;
                rv++;
            }
        }
    }
    return rv;
}