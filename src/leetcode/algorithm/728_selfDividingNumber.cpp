#include <vector>
using namespace std;
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> rv;
    for (int origin = left; origin <= right; ++origin) {
        int i = origin;
        bool ok = true;
        while (i != 0) {
            int divider = i % 10;
            if (divider != 0 && origin % divider == 0) {
                i /= 10;
                continue;
            }
            ok = false;
            break;
        }
        if (ok) {
            rv.push_back(origin);
        }
    }
    return rv;
}