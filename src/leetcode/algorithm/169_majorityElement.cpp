#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int pivot = 0;
    for (int num : nums) {
        if (count == 0) {
            pivot = num;
        }
        if (pivot == num) {
            ++count;
        } else {
            --count;
        }
    }
    return pivot;
}