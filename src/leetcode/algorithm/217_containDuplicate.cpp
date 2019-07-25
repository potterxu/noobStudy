#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int n : nums) {
        if (m.find(n) != m.end()) {
            return true;
        } else{
            m[n] = 0;
        }
    }
    return false;
}