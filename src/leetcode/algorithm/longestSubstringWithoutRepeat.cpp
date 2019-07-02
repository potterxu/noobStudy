/*
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Example 1:
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * Example 2:
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * Example 3:
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. Note that the answer
 * must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubString(string s) {
    unordered_map<char,int> hash;
    int max_len = 0;
    size_t starting_index = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        auto it = hash.find(s[i]);
        if (it != hash.end()) {
            size_t new_starting = hash[s[i]] + 1;
            if (new_starting > starting_index) {
                starting_index = new_starting;
            }
        }
        int len = i - starting_index + 1;
        if (len > max_len) {
            max_len = len;
        }
        hash[s[i]] = i;
    }
    return max_len;
}