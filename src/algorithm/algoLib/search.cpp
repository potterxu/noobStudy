#include "search.hpp"

namespace pxu {
using namespace std;

int _binarySearch(const vector<int> &vec, int target, int left, int right) {
    if (right < left) {
        return -1;
    }
    int i = (left + right) / 2;
    if (vec[i] == target) {
        return i;
    } else if (target > vec[i]) {
        return _binarySearch(vec, target, i + 1, right);
    } else {
        return _binarySearch(vec, target, left, i - 1);
    }
}

int binarySearch(const vector<int> &vec, int target)
{
    return _binarySearch(vec, target, 0, vec.size()-1);
}
}