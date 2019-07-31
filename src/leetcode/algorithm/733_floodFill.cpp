#include <vector>
using namespace std;

void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
    if (image[r][c] != color) {
        return;
    }
    image[r][c] = newColor;
    if (r > 0) {
        dfs(image, r - 1, c, color, newColor);
    }
    if (r < image.size() - 1) {
        dfs(image, r + 1, c, color, newColor);
    }
    if (c > 0) {
        dfs(image, r, c - 1, color, newColor);
    }
    if (c < image[0].size() - 1) {
        dfs(image, r, c + 1, color, newColor);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image[sr][sc] == newColor) {
        return image;
    }
    dfs(image, sr, sc, image[sr][sc], newColor);
    return image;
}