#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& A) {
    int min = 0, max = A.size() - 1, rv = 0;
    while (min <= max) {
        int i = (min + max) / 2;
        if (A[i] < A[i + 1]) {
            min = i + 1;
        } else if (A[i] < A[i - 1]) {
            max = i - 1;
        } else {
            rv = i;
            break;
        }
    }
    return rv;
}