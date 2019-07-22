#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if (r * c > nums.size() * nums[0].size()) {
        return nums;
    }
    vector<vector<int>> rv(r, vector<int>(c));
    int ri = 0;
    int ci = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[0].size(); ++j) {
            rv[ri][ci] = nums[i][j];
            ++ci;
            if (ci >= c) {
                ci -= c;
                ++ri;
            }
        }
    }
    return rv;
}