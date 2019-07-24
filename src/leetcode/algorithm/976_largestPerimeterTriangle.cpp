#include <vector>
using namespace std;

int largestPerimeter(vector<int>& A) {
    int rv = 0;
    sort(A.begin(), A.end());
    for (int i = A.size() - 1; i >= 2; --i) {
        if (A[i-2] + A[i-1] > A[i]) {
            rv = A[i-2] + A[i-1] + A[i];
            break;
        }
    }
    return rv;
}