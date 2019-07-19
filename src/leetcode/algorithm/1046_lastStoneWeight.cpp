#include <vector>
#include <algorithm>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    int rv = 0;
    sort(stones.begin(), stones.end());
    int end = stones.size() - 1;
    while (end >= 0) {
        if (end == 0) {
            rv = stones[0];
            break;
        } else {
            if (stones[end] == stones[end - 1]) {
                end -= 2;
            } else {
                stones[end - 1] = stones[end] - stones[end - 1];
                end--;
                int pivot = end;
                while (pivot > 0 && stones[pivot - 1] > stones[pivot]) {
                    swap(stones[pivot-1], stones[pivot]);
                    pivot--;
                }
            }
        }
    }
    return rv;
}