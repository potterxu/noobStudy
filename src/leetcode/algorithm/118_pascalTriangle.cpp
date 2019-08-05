#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> rv(numRows);
    for (int i = 0; i < numRows; ++i) {
        rv[i] = vector<int>(i+1, 1);
        for (int j = 1; j < i; ++j) {
            rv[i][j] = rv[i-1][j-1] + rv[i-1][j];
        }
    }
    return rv;
}