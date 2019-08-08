#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> rv(rowIndex+1, 0);
    rv[0] = 1;
    for (int i = 1; i < rowIndex + 1; ++i) {
        for (int j = i; j > 0; --j) {
            rv[j] += rv[j-1];
        }
    }
    return rv;
}