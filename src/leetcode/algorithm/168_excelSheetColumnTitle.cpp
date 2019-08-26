#include <string>
#include <algorithm>
using namespace std;

string convertToTitle(int n) {
    string rv;
    while (n > 0) {
        --n;
        rv.push_back(n % 26 + 'A');
        n /= 26;
    }
    reverse(rv.begin(), rv.end());
    return rv;
}