/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (30.87%)
 * Likes:    2278
 * Dislikes: 399
 * Total Accepted:    258.2K
 * Total Submissions: 791.2K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */

class Solution {
public:
    class Trie{
        public:
        ~Trie(){
            for (auto p : child) {
                delete p.second;
                p.second = nullptr;
            }
        }
        void insert(const string &s) {
            if (s.empty()) {
                return;
            }
            _insert(s, 0);
        }
        bool hasString(const string &s, int start, int end) {
            if (start > end) {
                return false;
            }
            if (child[s[start]] == nullptr) {
                return false;
            }
            if (start == end) {
                return child[s[start]]->exist;
            }
            return child[s[start]]->hasString(s, start+1, end);
        }

        private:
        void _insert(const string &s, int i) {
            if (child[s[i]] == nullptr) {
                child[s[i]] = new Trie();
            }
            if (i == s.size() - 1) {
                child[s[i]]->exist = true;
                return;
            }
            child[s[i]]->_insert(s, i+1);
        }
        bool exist = false;
        unordered_map<char, Trie*> child;
    };
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie = Trie();
        unordered_map<char, bool> m;
        for (auto &str : wordDict) {
            trie.insert(str);
            for (auto c : str) {
                m[c] = true;
            }
        }
        for (char c : s) {
            if (m[c] == false) {
                return vector<string>();
            }
        }
        vector<vector<string>> dp(s.size());
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (trie.hasString(s, j, i)) {
                    string substr = s.substr(j, i-j+1);
                    if (j > 0) {
                        for (string &str : dp[j-1]) {
                            dp[i].push_back(str);
                            dp[i].back() += " ";
                            dp[i].back() += substr;
                        }
                    } else {
                        dp[i].push_back(substr);
                    }
                }
            }
        }
        return dp[s.size()-1];
    }
};