#include <vector>
#include <string>
using namespace std;

vector<int> diStringMatch(string S) {
    vector<int> rv;
    int min = 0, max = S.size();
    for (char s : S) {
        if (s == 'I') {
            rv.push_back(min);
            min++;
        } else {
            rv.push_back(max);
            max--;
        }
    }
    rv.push_back(min);
    return rv;
}