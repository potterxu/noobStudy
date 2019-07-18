#include <string>
#include <vector>

using namespace std;

vector<string> commonChars(vector<string>& A) {
    vector<int> minVec(26, 100);
    vector<string> rv;
    for (string s : A) {
        vector<int> vec(26, 0);
        for (char c : s) {
            vec[c - 'a']++;
        }
        for (int i = 0; i< 26; ++i) {
            if (vec[i] < minVec[i]) {
                minVec[i] = vec[i];
            }
        }
    }
    char c = 'a';
    for (int i : minVec) {
        for (int j = 0; j < i; ++j) {
            string out;
            out.push_back(c);
            rv.push_back(out);
        }
        ++c;
    }
    return rv;
}