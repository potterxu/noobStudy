#include <string>
#include <vector>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    int dict[26];
    for (int i = 0; i < order.size(); ++i) {
        dict[order[i] - 'a'] = i;
    }
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            if (j == words[i+1].size()) {
                return false;
            }
            if (dict[words[i][j] - 'a'] > dict[words[i+1][j] - 'a']) {
                return false;
            } else if (dict[words[i][j] - 'a'] < dict[words[i+1][j] - 'a']) {
                break;
            }
        }
    }
    return true;
}