class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rv;
        if (matrix.empty() || matrix[0].empty()) {
            return rv;
        }
        int x = 0;
        int y = 0;
        int xLength = matrix.size();
        int yLength = matrix[0].size();
        while (xLength > 0 && yLength > 0) {
            //sphere by sphere
            for (int i = 0; i < yLength; ++i) {
                rv.push_back(matrix[x][y+i]);
            }
            for (int i = 1; i < xLength; ++i) {
                rv.push_back(matrix[x+i][y+yLength-1]);
            }
            if (xLength >= 2 && yLength >= 2) {
                for (int i = yLength-2; i >=0; --i) {
                    rv.push_back(matrix[x+xLength-1][y+i]);
                }
                if (xLength >= 3) {
                    for (int i = xLength-2; i >= 1; --i) {
                        rv.push_back(matrix[x+i][y]);
                    }
                }
            }
            ++x;
            ++y;
            xLength -= 2;
            yLength -= 2;
        }
        return rv;
    }
};