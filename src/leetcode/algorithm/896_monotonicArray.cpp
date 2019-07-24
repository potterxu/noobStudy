#include <vector>
using namespace std;

bool isMonotonic(vector<int>& A) {
    if (A.size() < 2) {
        return true;
    }
    bool inc = true, dec = true;
    for (int i = 0; i < A.size() - 1; ++i) {
        if (A[i] < A[i+1]) {
            dec = false;
        } else if (A[i] > A[i+1]) {
            inc = false;
        }
    }
    return inc || dec;
}