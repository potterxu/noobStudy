#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    return a == 0 ? b : gcd(b % a, a);
}
bool hasGroupsSizeX(vector<int>& deck) {
    if (deck.size() < 2) {
        return false;
    }
    unordered_map<int, int> m;
    for (int i : deck) {
        ++m[i];
    }
    int a = -1;
    for (auto &p : m) {
        if (a == -1) {
            a = gcd(deck.size(), p.second);
        } else {
            a = gcd(a, p.second);
        }
        if (a == 1) {
            return false;
        }
    }
    return true;
}