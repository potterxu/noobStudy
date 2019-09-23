#include <vector>
using namespace std;

namespace considerOverflow {
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k < 1) {
            return 0;
        }
        int rv = 0;
        int i = 0;
        int j = 0;
        int product = 1;
        while(i < nums.size()) {
           while (j < nums.size()) {
                if (k / nums[j] < product || product * nums[j] == k) {
                    break;
                }
               product *= nums[j];
               ++j;
            }
            rv += j - i;
            product /= nums[i];
            ++i;
            if (i > j && i < nums.size()) {
                j = i;
                product = nums[i];
            }
        }
        return rv;
    }
};

namespace noOverflow {
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k < 1) {
            return 0;
        }
        int rv = 0;
        int i = 0;
        int j = 0;
        int product = 1;
        while(i < nums.size()) {
            if (i > j) {
                j = i;
                product = nums[i];
            }
           while (j < nums.size()) {
               if (product * nums[j] < k) {
                    product *= nums[j];
                    ++j;
               } else {
                   break;
               }
            }
            rv += j - i;
            product /= nums[i];
            ++i;
        }
        return rv;
    }
};