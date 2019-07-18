#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> m;
    vector<string> rv;
    for (string s : cpdomains) {
        int index = s.find(' ');
        int number = stoi(s.substr(0, index));
        string domain = s.substr(index + 1, s.size() - index - 1);
        if (m.find(domain) == m.end()) {
            m[domain] = number;
        } else {
            m[domain] += number;
        }
        index = domain.find('.');
        while (index != string::npos) {
            domain = domain.substr(index + 1, domain.size() - index - 1);
            if (m.find(domain) == m.end()) {
                m[domain] = number;
            } else {
                m[domain] += number;
            }
            index = domain.find('.');
        }
    }
    for (auto p : m) {
        string s;
        s += to_string(p.second);
        s += " ";
        s += p.first;
        rv.push_back(s);
    }
    return rv;
}