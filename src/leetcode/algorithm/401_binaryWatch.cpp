#include <string>
#include <vector>
using namespace std;

vector<string> readBinaryWatch(int num) {
    static bool init = false;
    static vector<vector<int>> v(7, vector<int>());
    if (!init) {
        for (int i = 0; i < 60; ++i) {
            int n = i;
            int c = 0;
            while (n != 0) {
                n &= (n-1);
                ++c;
            }
            v[c].push_back(i);
        }
        init = true;
    }
    printf("inited\n");
    vector<string> rv;
    if (num > 10) {
        return rv;
    }
    int max = 4;
    if (num < max) {
        max = num;
    }
    for (int i = 0; i <= max; ++i) {
        if (num - i > 6) {
            continue;
        }
        for (int h : v[i]) {
            if (h > 11) {
                continue;
            }
            for (int m : v[num - i]) {
                string s = to_string(h);
                s.push_back(':');
                if (m < 10) {
                    s.push_back('0');
                }
                s += to_string(m);
                rv.push_back(s);
            }
        }
    }
    return rv;
}