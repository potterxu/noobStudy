#include<vector>
using namespace std;
vector<int> sortedSquares(vector<int>& A) {
    vector<int> rv = vector<int>(A.size(), 0);
    int begin = 0;
    int end = A.size() - 1;
    int rvIndex = A.size() - 1;
    while (begin <= end) {
        if (A[begin] + A[end] > 0) {
            rv[rvIndex] = A[end] * A[end];
            end--;
        } else {
            rv[rvIndex] = A[begin] * A[begin];
            begin++;
        }
        rvIndex--;
    }
    return rv;
}