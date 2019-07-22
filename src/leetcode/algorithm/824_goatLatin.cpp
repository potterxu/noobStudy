#include <string>
#include <vector>
using namespace std;

string toGoatLatin(string S) {
    string rv;
    static int d[26] {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    int numOfa = 1;
    int index = 0;
    string w;
    while (index <= S.size()) {
        if (S[index] == ' ' || index == S.size()) {
            if (d[(w[0] >= 'a' ? (w[0] - 'a') : (w[0] - 'A'))]) {
                rv += w;
            } else {
                rv += w.substr(1, w.size() - 1);
                rv.push_back(w[0]);
            }
            rv += "ma";
            for (int i = 0; i < numOfa; ++i) {
                rv.push_back('a');
            }
            if (index < S.size()) {
                rv.push_back(' ');
            }
            ++numOfa;
            w = "";
        } else {
            w.push_back(S[index]);
        }
        ++index;
    }
    return rv;
}