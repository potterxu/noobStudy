#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    bool needMoreSpace = true;
    for (int d : digits) {
        if (d != 9){
            needMoreSpace = false;
            break;
        }
    }
    if (needMoreSpace) {
        vector<int> rv(digits.size() + 1, 0);
        rv[0] = 1;
        return rv;
    } else {
        int carry = 1;
        for (int i = digits.size()-1; i > -1; --i) {
            digits[i] += carry;
            if (digits[i] > 9) {
                digits[i] -= 10;
                carry = 1;
            } else {
                break;
            }
        }
        return digits;
    }
}