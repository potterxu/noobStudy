class Solution {
public:
    int balancedStringSplit(string s) {
        // greedy, each time take the shortest balance substring
        int rv = 0;
        int c = 0;
        for (char a : s) {
            if (a == 'L') {
                ++c;
            } else {
                --c;
            }
            if (c == 0) {
                ++rv;
            }
        }
        return rv;
    }
};
