/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (47.86%)
 * Likes:    2995
 * Dislikes: 48
 * Total Accepted:    307K
 * Total Submissions: 641.3K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */

// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *trie = this;
        for (char c : word) {
            if (!trie->m_trie[c-'a']) {
                trie->m_trie[c-'a'] = new Trie();
            }
            trie = trie->m_trie[c-'a'];
        }
        trie->m_exist = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *trie = this;
        for(char c : word) {
            if (!trie->m_trie[c-'a']) {
                return false;
            }
            trie = trie->m_trie[c-'a'];
        }
        return trie->m_exist;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *trie = this;
        for(char c : prefix) {
            if (!trie->m_trie[c-'a']) {
                return false;
            }
            trie = trie->m_trie[c-'a'];
        }
        return true;
    }
private:
    Trie* m_trie[26] = { nullptr };
    bool m_exist = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
