/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 *
 * https://leetcode.com/problems/trapping-rain-water-ii/description/
 *
 * algorithms
 * Hard (41.45%)
 * Likes:    1365
 * Dislikes: 31
 * Total Accepted:    42.9K
 * Total Submissions: 100.9K
 * Testcase Example:  '[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]'
 *
 * Given an m x n matrix of positive integers representing the height of each
 * unit cell in a 2D elevation map, compute the volume of water it is able to
 * trap after raining.
 * 
 * Example:
 * 
 * 
 * Given the following 3x6 height map:
 * [
 * ⁠ [1,4,3,1,3,2],
 * ⁠ [3,2,1,3,2,4],
 * ⁠ [2,3,3,2,3,1]
 * ]
 * 
 * Return 4.
 * 
 * 
 * 
 * 
 * The above image represents the elevation map
 * [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
 * 
 * 
 * 
 * 
 * 
 * After the rain, water is trapped between the blocks. The total volume of
 * water trapped is 4.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 110
 * 0 <= heightMap[i][j] <= 20000
 * 
 * 
 */

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() < 3 || heightMap[0].size() < 3) {
            return 0;
        }
        // 逐圈往里进行缩进， 用小顶优先队列存储外圈的长度，然后不断缩小圈的范围进行求解
        vector<vector<int>> visited(heightMap.size(), vector<int>(heightMap[0].size(), -1));
        auto cmp = [&](const vector<int> &a, const vector<int> &b) {
            return heightMap[a[0]][a[1]] >= heightMap[b[0]][b[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < heightMap.size(); ++i) {
            visited[i][0] = 1;
            visited[i].back() = 1;
            q.push({i, 0});
            q.push({i, (int)heightMap[0].size()-1});
        }
        for (int j = 0; j < heightMap[0].size(); ++j) {
            visited[0][j] = 1;
            visited.back()[j] = 1;
            q.push({0, j});
            q.push({(int)heightMap.size()-1, j});
        }
        int rv = 0;
        while (!q.empty()) {
            auto v = q.top();
            //printf("%d, %d\n", v[0], v[1]);
            q.pop();
            for (int i = v[0]-1; i <= v[0] + 1; ++i) {
                if (i < 0 || i >= heightMap.size()) {
                    continue;
                }
                for (int j = v[1]-1; j <= v[1]+1; ++j) {
                    if (j < 0 || j >= heightMap[0].size() || abs(i+j-v[0]-v[1]) != 1) {
                        continue;
                    }
                    if (visited[i][j] != -1) {
                        continue;
                    }
                    visited[i][j] = 1;
                    if (heightMap[i][j] < heightMap[v[0]][v[1]]) {
                        rv += heightMap[v[0]][v[1]] - heightMap[i][j];
                        heightMap[i][j] = heightMap[v[0]][v[1]];
                    }
                    //printf("%d, %d, %d\n", i, j, heightMap[i][j]);
                    q.push({i,j});
                }
            }
        }
        return rv;
    }
};
