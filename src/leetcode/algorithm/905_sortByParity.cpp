#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    int fromStart = 0;
    int fromEnd = A.size() - 1;
    while (fromStart < fromEnd) {
        if (A[fromStart] % 2 == 0) {
            fromStart++;
        } else {
            if (A[fromEnd] % 2 == 0) {
                A[fromStart] += A[fromEnd];
                A[fromEnd] = A[fromStart] - A[fromEnd];
                A[fromStart] = A[fromStart] - A[fromEnd];
                fromStart++;
            }
            fromEnd--;
        }
    }
    return A;
}