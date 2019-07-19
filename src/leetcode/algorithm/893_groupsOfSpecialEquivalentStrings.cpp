#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int numSpecialEquivGroups(vector<string>& A) {
    unordered_map<string, int> m;
    for (string s : A) {
        string even, odd;
        for (int i = 0; i < s.size(); i = i + 2) {
            even += s[i];
            if (i + 1 < s.size()) {
                odd += s[i+1];
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        even += odd;
        if (m.find(even) == m.end()) {
            m[even] = 1;
        }
    }
    return m.size();
}