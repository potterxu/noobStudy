#include <vector>
using namespace std;

int binarySearch(vector<int> &numbers, int start, int end, int num) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (num < numbers[mid]) {
            end = mid - 1;
        } else if (num > numbers[mid]) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> rv;
    for (int i = 0; i < numbers.size(); ++i) {
        int remainI = binarySearch(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
        if (remainI != -1) {
            rv.push_back(i + 1);
            rv.push_back(remainI + 1);
            break;
        }
    }
    return rv;
}