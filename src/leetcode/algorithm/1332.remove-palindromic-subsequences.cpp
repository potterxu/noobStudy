class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) {
            return 0;
        }
        int start = 0;
        int end = s.size()-1;
        while (start < end) {
            if (s[start] != s[end]) {
                return 2;
            }
            ++start;
            --end;
        }
        return 1;
    }
};
