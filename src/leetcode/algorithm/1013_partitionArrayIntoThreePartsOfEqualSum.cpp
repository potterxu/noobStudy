#include <vector>
using namespace std;

bool canThreePartsEqualSum(vector<int>& A) {
    for (int i = 1; i < A.size(); ++i) {
        A[i] += A[i-1];
    }
    if (A[A.size()-1] % 3 != 0) {
        return false;
    }
    int sum = A[A.size() - 1] / 3;
    auto it = find(A.begin(), A.end(), sum);
    it = find(it, A.end(), sum + sum);
    if (it != A.end()) {
        return true;
    }
    return false;
}