#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (auto &v : A) {
        int half = (v.size() + 1) / 2;
        for (int i = 0; i < half; ++i) {
            int reverseIndex = v.size() - 1 - i;
            if (i == reverseIndex) {
                v[i] = 1 - v[i];
                break;
            }
            v[i] = (1 - v[i]) + v[reverseIndex];
            v[reverseIndex] = v[i] - v[reverseIndex];
            v[i] = 1 - (v[i] - v[reverseIndex]);
        }
    }
    return A;
}