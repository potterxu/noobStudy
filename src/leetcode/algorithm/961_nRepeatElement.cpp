#include <vector>
#include <unordered_map>
using namespace std;
int repeatedNTimes(vector<int>& A) {
    unordered_map<int, int> m;
    int rv = A[0];
    for (int i : A) {
        if (m.find(i) != m.end()) {
            rv = i;
        }
        m[i] = 1;
    }
    return rv;
}