#include <vector>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    bool rv = true;
    for (int i = 0; i < matrix.size() - 1; ++i) {
        for (int j = 0; j < matrix[i].size() - 1; ++j) {
            if (matrix[i][j] != matrix[i+1][j+1]) {
                rv = false;
                break;
            }
        }
    }
    return rv;
}