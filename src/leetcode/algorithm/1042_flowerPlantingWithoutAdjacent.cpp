#include <vector>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<int> rv(N, 1);
    bool stop;
    do {
        stop = true;
        for (auto &v : paths) {
            int a = min(v[0], v[1]);
            int b = max(v[0], v[1]);
            if (rv[a-1] == rv[b-1]) {
                stop = false;
                ++rv[b-1];
                if (rv[b-1] > 4) {
                    rv[b-1] = 1;
                }
            }
        }
    } while(!stop);
    return rv;
}