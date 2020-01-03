class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<vector<int>> m = vector<vector<int>>(26, vector<int>(2, 0)); //[max, count];
        for (char c: chars) {
            ++m[c-'a'][0];
        }
        int rv = 0;
        for (string &s : words) {
            if (s.size() > chars.size()) {
                continue;
            }
            bool ok = true;
            for (char c : s) {
                if (m[c-'a'][1] == m[c-'a'][0]) {
                    ok = false;
                    break;
                }
                ++m[c-'a'][1];
            }
            if (ok) {
                rv += s.size();
            }
            for (auto &v : m) {
                v[1] = 0;
            }
        }
        return rv;
    }
};
