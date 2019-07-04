#include "sort.hpp"

namespace pxu {

using namespace std;

/*
 * Recusively move the minimum value to the front of the sub vector
 */
void _selectionSort(vector<int> &vec, int startIndex) {
    int pivotIndex = startIndex;
    for (int i = startIndex; i < vec.size(); ++i) {
        if (vec[i] < vec[pivotIndex]) {
            pivotIndex = i;
        }
    }
    if (pivotIndex != startIndex) {
        swap(vec[startIndex], vec[pivotIndex]);
    }
    if (startIndex < vec.size() - 1) {
        _selectionSort(vec, startIndex + 1);
    }
}

void selectionSort(vector<int> &vec)
{
    _selectionSort(vec, 0);
}

}