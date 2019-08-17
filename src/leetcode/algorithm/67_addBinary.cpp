#include <string>
using namespace std;

string addBinary(string a, string b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
    size_t i = 0;
    char carry = 0;
    string rv;
    while (i < b.size()) {
        char v = a[a.size() - 1 - i] + b[b.size() - 1 - i] - 96 + carry;
        if (v > 1) {
            v -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        rv.push_back(v + 48);
        ++i;
    }
    while (i < a.size()) {
        char v = a[a.size() - 1 - i] + carry - 48;
        if (v > 1) {
            v -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        rv.push_back(v + 48);
        ++i;
    }
    if (carry) {
        rv.push_back('1');
    }
    reverse(rv.begin(), rv.end());
    return rv;
}