#include <unordered_map>
#include <vector>
using namespace std;

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sumA = 0, sumB = 0;
    unordered_map<int, int> m;
    for (int a : A) {
        sumA += a;
    }
    for (int b : B) {
        sumB += b;
        m[b] = 1;
    }
    int diff = (sumB - sumA) / 2;
    vector<int> rv(2);
    for (int a : A) {
        if (a + diff > 0 && m.find(a + diff) != m.end()) {
            rv[0] = a;
            rv[1] = a + diff;
            break;
        }
    }
    return rv;
}