#include <string>
#include <vector>

using namespace std;

int minDeletionSize(vector<string>& A) {
    int rv = 0;
    for (size_t i = 0; i < A[0].size(); ++i) {
        for (size_t j = 0; j < A.size() - 1; ++j) {
            if (A[j][i] > A[j+1][i]) {
                rv++;
                break;
            }
        }
    }
    return rv;
}