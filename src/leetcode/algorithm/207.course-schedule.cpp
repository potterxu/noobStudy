/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (42.39%)
 * Likes:    4026
 * Dislikes: 181
 * Total Accepted:    433.6K
 * Total Submissions: 1M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

class Solution {
public:
    bool dfs(vector<vector<int>> &v, vector<int> &visited, int course) {
        if (visited[course] == 0) {
            return false;
        }
        if (visited[course] == 1) {
            return true;
        }
        visited[course] = 0;
        for (int c : v[course]) {
            if (!dfs(v, visited, c)) {
                return false;
            }
        }
        visited[course] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses); // v[course] = [] of prerequest-course
        for (auto &p : prerequisites) {
            v[p[0]].push_back(p[1]);
        }
        vector<int> visited(numCourses, -1); // -1 unvisited, 0 in searching, 1 searched valid
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == -1) {
                if (!dfs(v, visited, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};
