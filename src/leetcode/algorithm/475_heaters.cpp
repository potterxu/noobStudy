#include <algorithm>
#include <vector>
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int i = 0;
    int j = 0;
    int r = 0;
    int rv = 0;
    if (heaters.size() == 1) {
        while (i < houses.size()) {
            rv = max(rv, abs(heaters[0] - houses[i]));
            ++i;
        }
        return rv;
    }
    while (j+1 < heaters.size() && i < houses.size()) {
        if (heaters[j] <= houses[i] && heaters[j+1] >= houses[i]) {
            r = min(houses[i] - heaters[j], heaters[j+1] - houses[i]);
            ++i;
            rv = max(r, rv);
        } else if (heaters[j] > houses[i]) {
            r = heaters[j] - houses[i];
            rv = max(r, rv);
            ++i;
        } else {
            ++j;
        }
    }
    if (i < houses.size()) {
        return max(rv, houses[houses.size() - 1] - heaters[heaters.size() - 1]);
    } 
    return rv;
}