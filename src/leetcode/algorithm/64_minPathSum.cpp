#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> sum = vector<vector<int>>(grid.size(), vector<int>(grid[0].size()));
    sum[0][0] = grid[0][0];
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (i==0 && j==0) {
                continue;
            }
            if (i == 0) {
                sum[i][j] = sum[i][j-1] + grid[i][j];
                continue;
            }
            if (j == 0) {
                sum[i][j] = sum[i-1][j] + grid[i][j];
                continue;
            }
            sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
        }
    }
    return sum[grid.size()-1][grid[0].size()-1];
}