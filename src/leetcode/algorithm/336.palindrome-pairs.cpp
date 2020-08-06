/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (33.34%)
 * Likes:    1381
 * Dislikes: 155
 * Total Accepted:    100.5K
 * Total Submissions: 298.8K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]] 
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]] 
 * Explanation: The palindromes are ["battab","tabbat"]
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    class Trie {
        public:
        void insert(const string &s, int i, int p) {
            if (i == s.size()) {
                pos = p;
                return;
            }
            if (v[s[i] - 'a'] == nullptr) {
                v[s[i] - 'a'] = new Trie();
            }
            v[s[i]-'a']->insert(s, i+1, p);
        }
        int find(const string &s, int start, int end) {
            if (s == "") {
                return pos;
            }
            if (v[s[start]-'a'] == nullptr) {
                return -1;
            }
            if (start == end) {
                return v[s[start]-'a']->pos;
            } else if (start > end) {
                return v[s[start]-'a']->find(s, start-1, end);
            } else {
                return v[s[start]-'a']->find(s, start+1, end);
            }
        }
        private:
        vector<Trie*> v = vector<Trie*>(26, nullptr);
        int pos = -1;
    };

    bool ispalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie t;
        
        vector<vector<int>> rv;
        for (int p = 0; p < words.size(); ++p) {
            t.insert(words[p], 0, p);
        }
        for (int p = 0; p < words.size(); ++p) {
            string &s = words[p];
            if (s == "") {
                continue;
            }
            int pair = t.find(s, s.size()-1, 0);
            if (pair != -1 && pair != p) {
                rv.push_back({p, pair});
            }
            if (ispalindrome(s, 0, s.size()-1)) {
                pair = t.find("", -1, -1);
                if (pair != -1) {
                    rv.push_back({p, pair});
                    rv.push_back({pair, p});
                }
            }
            for (int i = 0; i < s.size()-1; ++i) {
                if (ispalindrome(s, 0, i)) {
                    pair = t.find(s, s.size()-1, i+1);
                    if (pair != -1 && pair != p) {
                        rv.push_back({pair, p});
                    }
                }
            }
            for (int i = s.size()-1; i>0; --i) {
                if (ispalindrome(s, i, s.size()-1)) {
                    pair = t.find(s, i-1, 0);
                    if (pair != -1 && pair != p) {
                        rv.push_back({p, pair});
                    }
                }
            }
        }
        return rv;
    }
};
