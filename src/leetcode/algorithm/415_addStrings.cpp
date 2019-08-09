#include <algorithm>
#include <string>
using namespace std;

string addStrings(string num1, string num2) {
    string rv;
    if (num1.size() < num2.size()) {
        swap(num1, num2);
    }
    char carry = 0;
    int i = 0;
    while (i < num2.size()) {
        char sum = num1[num1.size() - 1 - i] + num2[num2.size() - 1 - i] - 48 - 48 + carry;
        if (sum > 9) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        rv.push_back(sum + 48);
        ++i;
    }
    while (i < num1.size()) {
        char sum = num1[num1.size() - 1 - i] - 48 + carry;
        if (sum > 9) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        rv.push_back(sum + 48);
        ++i;
    }
    if (carry > 0) {
        rv.push_back('1');
    }
    reverse(rv.begin(), rv.end());
    return rv;
}