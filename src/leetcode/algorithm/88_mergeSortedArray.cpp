#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int ptr = nums1.size() - nums2.size();
    for (int n : nums2) {
        nums1[ptr] = n;
        for (int i = ptr; i > 0; --i) {
            if (nums1[i] < nums1[i-1]) {
                swap(nums1[i], nums1[i-1]);
            }
        }
        ++ptr;
    }
}