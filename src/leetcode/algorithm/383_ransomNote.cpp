#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int a[26]{0};
    for (char c : ransomNote) {
        ++a[c-'a'];
    }
    for (char c : magazine) {
        --a[c-'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (a[i] > 0) {
            return false;
        }
    }
    return true;
}