#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    for (int i = 0; i < nums1.size(); ++i) {
        int num = nums1[i];
        auto it = find(nums2.begin(), nums2.end(), num);
        while (it != nums2.end()) {
            if (*it > num) {
                num = *it;
                break;
            }
            ++it;
        }
        nums1[i] = num > nums1[i] ? num : -1;
    }
    return nums1;
}