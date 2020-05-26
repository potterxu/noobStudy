class Solution {
public:
    void process(vector<vector<int>>& matrix, int x, int y, int xL, int yL, vector<int> &rv, int i) {
        if (xL <= 0 || yL <= 0) {
            return;
        }
        
        if (xL == 1 && yL == 1) {
           rv[i] = matrix[x][y];
            return;
        }
     
        for (int c = 0; c < yL; ++c) {
            rv[i] = matrix[x][y+c];
            ++i;
        }

      
        for (int c = 1; c < xL; ++c) {
            rv[i] = matrix[x+c][y + yL -1];
            ++i;
        }

        if (xL > 1 && yL > 1) {
            for (int c = 1; c < yL; ++c) {
                rv[i] = matrix[x+xL-1][y+yL-1-c];
                ++i;
            }
            if (xL > 2) {
                for (int c = 1; c < xL -1; ++c) {
                    rv[i] = matrix[x+xL-1-c][y];
                    ++i;
                }
            } 
        }
        process(matrix, x+1, y+1, xL-2, yL-2, rv, i);
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }
        vector<int> rv(matrix.size() * matrix[0].size());
        process(matrix, 0, 0, matrix.size(), matrix[0].size(), rv, 0);
        return rv;
    }
};
