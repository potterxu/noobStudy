#include <vector>

using namespace std;

int projectionArea(vector<vector<int>>& grid) {
    int rv = 0;
    for (int y = 0; y < grid.size(); ++y) {
        int m_xz = 0, m_yz = 0;
        for (int x = 0; x < grid.size(); ++x) {
            if (grid[x][y] != 0) {
                rv++;
            }
            if (grid[y][x] > m_xz) {
                m_xz = grid[y][x];
            }
            if (grid[x][y] > m_yz) {
                m_yz = grid[x][y];
            }
        }
        rv += m_xz;
        rv += m_yz;
    }
    return rv;
}