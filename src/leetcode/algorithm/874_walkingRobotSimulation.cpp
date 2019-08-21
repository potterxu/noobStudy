#include <vector>
#include <unordered_map>
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int rv = 0;
    unordered_map<int, unordered_map<int, int>> m;
    for (auto &vec : obstacles) {
        m[vec[0]][vec[1]] = 1;
    }
    int x = 0;
    int y = 0;
    int dI = 3;
    static vector<vector<int>> direction {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    for (int c : commands) {
        if (c == -2) {
            --dI;
            if (dI < 0) {
                dI += 4;
            }
            continue;
        }
        if (c == -1) {
            ++dI;
            if (dI > 3) {
                dI -= 4;
            }
            continue;
        }
        if (direction[dI][0] != 0) {
            for (int i = 0; i < c; ++i) {
                if (m[x+direction[dI][0]][y]) {
                    break;
                } 
                x += direction[dI][0];
            }
        } else {
            for (int i = 0; i < c; ++i) {
                if (m[x][y+direction[dI][1]]) {
                    break;
                }
                y += direction[dI][1];
            }
        }
        rv = max(rv, x*x + y*y);
    }
    return rv;
}