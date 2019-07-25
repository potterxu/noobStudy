#include <string>
using namespace std;

bool isUpper(char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}
bool detectCapitalUse(string word) {
    bool rv = true;
    if (isUpper(word[word.size() - 1])) {
        for (int i = 0; i < word.size() - 1; ++i) {
            rv &= isUpper(word[i]);
        }
    } else {
        for (int i = 1; i < word.size() - 1; ++i) {
            rv &= !isUpper(word[i]);
        }
    }
    return rv;
}