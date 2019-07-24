#include <set>
#include <vector>
using namespace std;
int twoCitySchedCost(vector<vector<int>>& costs) {
    multiset<int> s;
    int sum = 0;
    for (auto vec : costs) {
        sum += vec[0];
        s.insert(vec[1] - vec[0]);
    }
    auto it = s.begin();
    for (int i = 0; i < costs.size()/2; ++i) {
        sum += *it;
        ++it;
    }
    return sum;
}