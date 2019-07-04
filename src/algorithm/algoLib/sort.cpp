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

/*
 * Recursively doing bubble sorting on the sub vector
 */
void _bubbleSort(vector<int> &vec, int startIndex)
{
    if (startIndex == vec.size() - 1) {
        return;
    }
    for (int i = vec.size() - 1; i > startIndex; --i) {
        if (vec[i] < vec[i-1]) {
            swap(vec[i], vec[i-1]);
        }
    }
    _bubbleSort(vec, startIndex + 1);
}

void _insertSort(std::vector<int> &vec, int pivotIndex) {
    if (pivotIndex == vec.size()) {
        return;
    }
    int target = vec[pivotIndex];
    for (int i = pivotIndex - 1; i >= 0; --i) {
        if (target < vec[i]) {
            vec[pivotIndex] = vec[i];
            pivotIndex = i;
        }
    }
    vec[pivotIndex] = target;
    _insertSort(vec, pivotIndex+1);
}

void selectionSort(vector<int> &vec)
{
    _selectionSort(vec, 0);
}

void bubbleSort(vector<int> &vec)
{
    _bubbleSort(vec, 0);
}

void insertSort(std::vector<int> &vec)
{
    _insertSort(vec, 1);
}

}