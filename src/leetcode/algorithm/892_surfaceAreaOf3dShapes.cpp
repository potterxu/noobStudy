#include <vector>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}
int surfaceArea(vector<vector<int>>& grid) {
    int s = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid.size(); ++j) {
            if (grid[i][j] > 0) {
                s += 2 + grid[i][j] * 4;
                if (i > 0) {
                    s -= 2 * min(grid[i-1][j], grid[i][j]);
                }
                if (j > 0) {
                    s -= 2 * min(grid[i][j], grid[i][j - 1]);
                }
            }
        }
    }
    return s;
}