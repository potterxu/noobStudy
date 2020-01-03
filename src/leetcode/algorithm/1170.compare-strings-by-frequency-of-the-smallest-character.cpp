class Solution {
public:
    int f(string &s) {
        if (s.empty()) {
            return 0;
        }
        char c = s[0];
        int rv = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] < c) {
                c = s[i];
                rv = 1;
            } else if (s[i] == c) {
                ++rv;
            }
        }
        return rv;
    }
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> rv = vector<int>(queries.size());
        vector<int> w = vector<int>(words.size());
        for (int i = 0; i < words.size(); ++i) {
            w[i] = f(words[i]);
        }
        sort(w.rbegin(), w.rend());
        for (int index = 0; index < rv.size(); ++index) {
            int value = f(queries[index]);
            int i = 0;
            while (i < w.size()) {
                if (value >= w[i]) {
                    break;
                }
                ++i;
            }
            rv[index] = i;
        }
        return rv;
    }
};
