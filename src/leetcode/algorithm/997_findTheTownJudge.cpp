#include <vector>
using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> v(N, 0);
    for (auto &vec : trust) {
        v[vec[0] - 1] = -1;
        if (v[vec[1] - 1] == -1) {
            continue;
        }
        ++v[vec[1] - 1];
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == N - 1) {
            return i+1;
        }
    }
    return -1;
}