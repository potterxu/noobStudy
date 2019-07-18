#include <deque>
#include <vector>

using namespace std;

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> rv;
    vector<vector<int>> vec(R, vector<int>(C, 0));
    deque<vector<int>> q;
    q.push_back({r0, c0});
    vec[r0][c0] = 1;
    
    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop_front();
        rv.push_back(v);
        if (v[0] - 1 >= 0 && vec[v[0] - 1][v[1]] == 0) {
            q.push_back({v[0] - 1, v[1]});
            vec[v[0] - 1][v[1]] = 1;
        }
        if (v[0] + 1 < R && vec[v[0] + 1][v[1]] == 0) {
            q.push_back({v[0] + 1, v[1]});
            vec[v[0] + 1][v[1]] = 1;
        }
        if (v[1] - 1 >= 0 && vec[v[0]][v[1] - 1] == 0) {
            q.push_back({v[0], v[1] - 1});
            vec[v[0]][v[1] - 1] = 1;
        }
        if (v[1] + 1 < C && vec[v[0]][v[1] + 1] == 0) {
            q.push_back({v[0], v[1] + 1});
            vec[v[0]][v[1] + 1] = 1;
        }
    }
    return rv;
}