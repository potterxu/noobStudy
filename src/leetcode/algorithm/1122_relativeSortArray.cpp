#include <vector>
#include <algorithm>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int fromStart = 0;
    for (int i : arr2) {
        int fromEnd = arr1.size() - 1;
        while (fromStart < fromEnd) {
            if (arr1[fromStart] != i && arr1[fromEnd] == i) {
                arr1[fromStart] += arr1[fromEnd];
                arr1[fromEnd] = arr1[fromStart] - arr1[fromEnd];
                arr1[fromStart] = arr1[fromStart] - arr1[fromEnd];
                fromStart++;
                fromEnd--;
            } else {
                if (arr1[fromStart] == i) {
                    fromStart++;
                }
                if (arr1[fromEnd] != i) {
                    fromEnd--;
                }
            }
        }
    }
    sort(arr1.begin() + fromStart, arr1.end());
    return arr1;
}