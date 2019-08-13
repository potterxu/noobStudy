#include <string>
using namespace std;

string countAndSay(int n) {
    string rv = "1";
    while (n > 1) {
        int count = 1;
        char cur = rv[0];
        string s;
        for (int i = 1; i < rv.size(); ++i) {
            if (rv[i] == cur) {
                ++count;
            } else {
                s += to_string(count);
                s.push_back(cur);
                count = 1;
                cur = rv[i];
            }
        }
        if (count > 0) {
            s += to_string(count);
            s.push_back(cur);
        }
        if (!s.empty()) {
            rv = s;
        }
        --n;
    }
    return rv;
}