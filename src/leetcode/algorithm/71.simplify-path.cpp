/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (32.00%)
 * Likes:    782
 * Dislikes: 1760
 * Total Accepted:    207.6K
 * Total Submissions: 644.7K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level.
 * 
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * 
 * Example 6:
 * 
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 * 
 */

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return path;
        }
        if (path == "/") {
            return path;
        }
        path.push_back('/');
        deque<string> q;
        string s = "";
        int ptr = 1;
        while (ptr < path.size()) {
            if (path[ptr] == '/') {
                if (!s.empty()) {
                    if (s == "..") {
                        if (!q.empty()) {
                            q.pop_back();
                        }
                    } else if (s != ".") {
                        q.push_back(s);
                    }
                }
                s = "";
            } else {
                s.push_back(path[ptr]);
            }
            ++ptr;
        }
        string rv = "";
        while (!q.empty()) {
            rv += "/";
            rv += q.front();
            q.pop_front();
        }
        if (rv.empty()) {
            rv = "/";
        }
        return rv;
    }
};