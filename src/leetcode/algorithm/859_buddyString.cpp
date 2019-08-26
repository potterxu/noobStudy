#include <string>
using namespace std;

bool buddyStrings(string A, string B) {
    if (A.size() != B.size()) {
        return false;
    }
    if (A.size() < 2) {
        return false;
    }
    int i = -1;
    int j = -1;
    char a[26] {0};
    bool hasDuplicate = false;
    for (int n = 0; n < A.size(); ++n) {
        if (a[A[n]-'a']) {
            hasDuplicate = true;
        }
        ++a[A[n] - 'a'];
        if (A[n] != B[n]) {
            if (i == -1) {
                i = n;
            } else if (j == -1) {
                j = n;
                if (A[i] != B[j] || A[j] != B[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    if (i != -1 && j != -1) {
        return true;
    } else if (i == -1 && j == -1) {
        return hasDuplicate;
    } else {
        return false;
    }
}