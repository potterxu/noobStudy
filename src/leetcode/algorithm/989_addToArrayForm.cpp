#include <algorithm>
#include <vector>
using namespace std;

vector<int> addToArrayForm(vector<int>& A, int K) {
    vector<int> rv;
    int carry = 0;;
    for (int i = 0; i < A.size(); ++i) {
        int sum = A[A.size() - 1 - i] + carry;
        if (K > 0) {
            sum += K%10;
            K /= 10;
        }
        if (sum > 9) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        rv.push_back(sum);
    }
    while (K > 0) {
        int sum = carry + K%10;
        K /= 10;
        if (sum > 9) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        rv.push_back(sum);
    }
    if (carry > 0) {
        rv.push_back(1);
    }
    reverse(rv.begin(), rv.end());
    return rv;
}