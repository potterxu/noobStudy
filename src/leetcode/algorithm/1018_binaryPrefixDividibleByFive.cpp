#include <vector>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& A) {
    vector<bool> rv(A.size());
    int num = 0;
    for (int i = 0; i < A.size(); ++i) {
        num += num + A[i];
        if (num >= 5) {
            num -= 5;
        }
        rv[i] = num == 0;
    }
    return rv;
}