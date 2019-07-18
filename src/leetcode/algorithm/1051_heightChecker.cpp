#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> tmp = heights;
    int rv = 0;
    sort(tmp.begin(), tmp.end());
    for (size_t i = 0; i < tmp.size(); ++i) {
        if (heights[i] != tmp[i]) {
            rv++;
        }
    }
    return rv;
}