/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (55.75%)
 * Likes:    3808
 * Dislikes: 194
 * Total Accepted:    717.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

class Solution {
public:
    string convertToKey(const string &s) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c-'a']++;
        }
        string rv = "";
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                rv.push_back(i+'a');
                rv += to_string(cnt[i]);
            }
        }
        return rv;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string &s : strs) {
            auto key = convertToKey(s);
            m[key].push_back(s);
        }
        vector<vector<string>>rv;
        for (auto &p : m) {
            rv.push_back(p.second);
        }
        return rv;
    }
};
