#include <string>
using namespace std;

string licenseKeyFormatting(string S, int K) {
    string rv;
    int count = 0;
    for (int i = S.size() - 1; i > -1; --i) {
        if (S[i] != '-') {
            if (count == K) {
                rv.push_back('-');
                count = 0;
            }
            rv.push_back(toupper(S[i]));
            ++count;
        }
    }
    reverse(rv.begin(), rv.end());
    return rv;
}