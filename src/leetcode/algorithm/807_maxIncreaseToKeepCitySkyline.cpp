#include <vector>
using namespace std;

int min(int a, int b) {
    return a < b ? a: b;
}

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    vector<int> rMax(grid.size(), 0);
    vector<int> cMax(grid.size(), 0);
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid.size(); ++j) {
            if (grid[j][i] > cMax[i]) {
                cMax[i] = grid[j][i];
            }
            if (grid[i][j] > rMax[i]) {
                rMax[i] = grid[i][j];
            }
        }
    }
    int rv = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid.size(); ++j) {
            rv += min(rMax[j], cMax[i]) - grid[i][j];
        }
    }
    return rv;
}