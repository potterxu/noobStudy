#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        m_v = vector<int>(nums.size(), 0);
        m_v[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            m_v[i] = m_v[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (j >= m_v.size()) {
            return 0;
        }
        int rv = m_v[j];
        if (i > 0) {
            rv -= m_v[i-1];
        }
        return rv;
    }
    
    vector<int> m_v;
};