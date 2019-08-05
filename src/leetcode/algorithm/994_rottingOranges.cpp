#include <deque>
#include <vector>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    deque<vector<int>> q;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 2) {
                q.push_back({i, j});
            }
        }
    }
    int rv = 0;
    bool first = true;
    while (!q.empty()) {
        size_t s = q.size();
        for (size_t i = 0; i < s; ++i) {
            auto &v = q.front();
            if (grid[v[0]][v[1]] != 1 && !first) {
                q.pop_front();
                continue;
            }
            grid[v[0]][v[1]] = -1;
            if (v[0] - 1 >= 0 && grid[v[0] - 1][v[1]] == 1) {
                q.push_back({v[0]-1, v[1]});
            }
            if (v[0] + 1 < grid.size() && grid[v[0] + 1][v[1]] == 1) {
                q.push_back({v[0]+1, v[1]});
            }
            if (v[1] - 1 >= 0 && grid[v[0]][v[1] - 1] == 1) {
                q.push_back({v[0], v[1]-1});
            }
            if (v[1] + 1 < grid[0].size() && grid[v[0]][v[1] + 1] == 1) {
                q.push_back({v[0], v[1]+1});
            }
            q.pop_front();
        }
        first = false;
        bool ok = false;
        for (auto &v : q) {
            if (grid[v[0]][v[1]] == 1) {
                ok = true;
                ++rv;
                break;
            }
        }
    }
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return rv;
}