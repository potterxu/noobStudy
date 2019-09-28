#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> rv;
    rv.push_back(vector<int>());
    for (int num : nums) {
        size_t size = rv.size();
        for (size_t s = 0; s < size; ++s) {
            rv.push_back(rv[s]);
            rv[rv.size() - 1].push_back(num);
        }
    }
    return rv;
}