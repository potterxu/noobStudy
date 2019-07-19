#include <string>
#include <vector>

using namespace std;

vector<int> numberOfLines(vector<int>& widths, string S) {
    vector<int> rv(2, 0);
    for (char c : S) {
        if (rv[1] + widths[c - 'a'] > 100) {
            rv[0]++;
            rv[1] = widths[c - 'a'];
        } else {
            rv[1] += widths[c - 'a'];
        }
    }
    if (rv[1] > 0) {
        rv[0]++;
    }
    return rv;
}