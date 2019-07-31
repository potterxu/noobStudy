#include <cmath>
#include <vector>
using namespace std;

vector<int> constructRectangle(int area) {
    int a = sqrt(area);
    vector<int> rv(2);
    for (int i = a; i > 0; --i) {
        if (area % i == 0) {
            rv[0] = area / i;
            rv[1] = i;
            break;
        }
    }
    return rv;
}