#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> m;
    for (int i = 0; i < list1.size(); ++i) {
            m[list1[i]] = i;
    }
    int min = 0x7fffffff;
    vector<string> rv;
    for (int i = 0; i < list2.size(); ++i) {
        if (m.find(list2[i]) != m.end()) {
            m[list2[i]] += i;
            if (m[list2[i]] < min) {
                min = m[list2[i]];
                rv.clear();
                rv.push_back(list2[i]);
            } else if (m[list2[i]] == min) {
                rv.push_back(list2[i]);
            }
        }
    }
    return rv;
}