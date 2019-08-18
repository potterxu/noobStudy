#include <unordered_map>
#include <vector>
using namespace std;

bool isMagic(vector<vector<int>>& grid, int r, int c) {
    if (r - 1 <= -1 || r + 1 >= grid.size() || c - 1 <= -1 || c + 1 >= grid[0].size()) {
        return false;
    }
    unordered_map<int, int> m;
    for (int i = -1; i <= 0; ++i) {
        for (int j = -1; j <= -i; ++ j) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (grid[r+i][c+j] + grid[r-i][c-j] == 10) {
                int v = min(grid[r+i][c+j], grid[r-i][c-j]);
                if (v < 1 || v > 4) {
                    return false;
                }
                if (m[v]) {
                    return false;
                }
                m[v] = 1;
            } else {
                return false;
            }
        }
    }
    if (grid[r-1][c-1] + grid[r-1][c] + grid[r-1][c+1] == 15
        && grid[r-1][c-1] + grid[r][c-1] + grid[r+1][c-1] == 15){
        return true;
    }
    return false;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int rv = 0;
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[0].size(); ++c) {
            if (grid[r][c] == 5) {
                if (isMagic(grid, r, c)) {
                    ++rv;
                }
            }
        }
    }
    return rv;
}