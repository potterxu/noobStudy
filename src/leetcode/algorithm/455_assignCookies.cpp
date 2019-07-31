#include <vector>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int gI = 0;
    int sI = 0;
    int rv = 0;
    while (sI != s.size() && gI != g.size()) {
        if (s[sI] >= g[gI]) {
            ++rv;
            ++gI;
        }
        ++sI;
    }
    return rv;
}