#include <vector>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    vector<vector<int>> rv (M.size(), vector<int>(M[0].size(), 0));
    for (int i = 0; i < M.size(); ++i) {
        for (int j = 0; j < M[0].size(); ++j) {
            int count = 0;
            for (int r = -1; r <= 1; ++r) {
                for (int c = -1; c <= 1; ++c) {
                    if (i + r < 0 || i + r >= M.size() || j + c < 0 || j + c >= M[0].size()) {
                        continue;
                    }
                    rv[i][j] += M[i+r][j+c];
                    ++count;
                }
            }
            rv[i][j] /= count;
        }
    }
    return rv;
}