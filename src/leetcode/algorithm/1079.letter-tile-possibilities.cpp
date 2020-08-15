/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 *
 * https://leetcode.com/problems/letter-tile-possibilities/description/
 *
 * algorithms
 * Medium (75.27%)
 * Likes:    705
 * Dislikes: 28
 * Total Accepted:    32.4K
 * Total Submissions: 43.1K
 * Testcase Example:  '"AAB"'
 *
 * You have a set of tiles, where each tile has one letter tiles[i] printed on
 * it.  Return the number of possible non-empty sequences of letters you can
 * make.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "AAB"
 * Output: 8
 * Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB",
 * "ABA", "BAA".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "AAABBC"
 * Output: 188
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= tiles.length <= 7
 * tiles consists of uppercase English letters.
 * 
 */

class Solution {
public:
    int count(map<int, int> &m) {
        int rv = 0;
        for (auto &p : m) {
            if (p.second == 0) {
                continue;
            }
            p.second--;
            rv++;
            rv += count(m);
            p.second++;
        }
        return rv;
    }
    int numTilePossibilities(string tiles) {
        map<int, int> m;
        for (char c : tiles) {
            m[c]++;
        }
        return count(m);
    }
};
