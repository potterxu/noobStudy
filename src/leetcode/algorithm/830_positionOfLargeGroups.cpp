#include <string>
#include <vector>
using namespace std;

vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> rv;
    char cur = ' ';
    int num = 0;
    vector<int> range(2, 0);
    for (int i = 0; i < S.size(); ++i) {
        if (cur == ' ') {
            cur = S[i];
            num = 1;
            range[0] = i;
        } else if (S[i] == cur) {
            ++num;
        } else {
            if (num >= 3) {
                range[1] = i - 1;
                rv.push_back(range);
            }
            cur = S[i];
            num = 1;
            range[0] = i;
        }
    }
    if (num >= 3) {
        range[1] = S.size() - 1;
        rv.push_back(range);
    }
    return rv;
}