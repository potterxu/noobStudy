#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> findRelativeRanks(vector<int>& nums) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]] = i;
    } 
    vector<string> rv(nums.size());
    int rank = nums.size();
    for (auto &p : m) {
        if (rank > 3) {
            rv[p.second] = to_string(rank);
        } else if (rank == 3) {
            rv[p.second] = "Bronze Medal";
        } else if (rank == 2) {
            rv[p.second] = "Silver Medal";
        } else if (rank == 1) {
            rv[p.second] = "Gold Medal";
        }
        --rank;
    }
    return rv;
}