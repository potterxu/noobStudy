#include <vector>
using namespace std;

int maxDistToClosest(vector<int>& seats) {
    int rv = -1;
    int distance = 0;
    for (int s : seats) {
        ++distance;
        if (s) {
            if (rv == -1) {
                rv = distance - 1;
            } else {
                rv = max(distance / 2, rv);
            }
            distance = 0;
        }
    }
    rv = max(distance, rv);
    return rv;
}