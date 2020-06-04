class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<unsigned int> a(s.size() + 1, 0);
        for (int i = 1; i < s.size() + 1; ++i) {
            a[i] = a[i-1] ^ (1u << (s[i-1]-'a'));
        }
        vector<bool> rv(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            auto &v = queries[i];
            if (v[0] == v[1]) {
                rv[i] = true;
            }
            if (v[2] >= (v[1] - v[0] + 1) / 2) {
                rv[i] = true;
                continue;
            }
            unsigned int diff = a[v[1]+1] ^ a[v[0]];
            int diffCount = 0;
            while (diff != 0) {
                diffCount++;
                diff &= (diff-1);
            }
            if (v[2] >= diffCount / 2) {
                rv[i] = true;
                continue;
            }
            rv[i] = false;
        }
        return rv;
    }
};
