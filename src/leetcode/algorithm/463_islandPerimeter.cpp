#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int rv = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 0) {
                continue;
            }
            rv += 4;
            if (i != 0 && grid[i-1][j] == 1) {
                rv--;
            }
            if (j != 0 && grid[i][j-1] == 1) {
                rv--;
            }
            if (i != grid.size() - 1 && grid[i+1][j] == 1) {
                rv--;
            }
            if (j != grid[i].size() - 1 && grid[i][j+1] == 1) {
                rv--;
            }
        }
    }
    return rv;
}