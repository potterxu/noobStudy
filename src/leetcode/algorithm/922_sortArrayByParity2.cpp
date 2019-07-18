#include <vector>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    int i = 0;
    int j = 1;
    while (i < A.size() && j < A.size()) {
        bool needSwap = true;
        if ((A[i] & 1) == 0) {

            needSwap = false;
            i += 2;
        }
        if ((A[j] & 1) != 0) {
            needSwap = false;
            j += 2;
        }
        if (needSwap) {
            A[i] += A[j];
            A[j] = A[i] - A[j];
            A[i] -= A[j];
            i += 2;
            j += 2;
        }
    }
    return A;
}