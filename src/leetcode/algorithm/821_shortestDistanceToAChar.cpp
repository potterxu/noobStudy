#include <string>
#include <vector>

using namespace std;

vector<int> shortestToChar(string S, char C) {
    vector<int> rv(S.size(), 0);
    int startC = S.find(C);
    for (int i = 0; i < startC; ++i) {
        rv[i] = startC - i;
    }
    int endC = startC + 1;
    while (endC < S.size()) {
        if (S[endC] == C) {
            for (int i = 1; i <= (endC - startC) / 2; ++i) {
                rv[startC + i] = i;
                rv[endC - i] = i;
            }
            startC = endC;
        }
        endC++;
    }
    for (int i = 1; i < S.size() - startC; ++i) {
        rv[startC + i] = i;
    }
    return rv;
}