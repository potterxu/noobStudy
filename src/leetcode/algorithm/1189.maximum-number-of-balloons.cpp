class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        map<char, int> m;
        for (char c : text) {
            ++m[c];
        }
        int rv = m['b'];
        rv = min(rv, m['a']);
        rv = min(rv, m['n']);
        rv = min(rv, min(m['l'], m['o'])/2);
        return rv;
    }
};
