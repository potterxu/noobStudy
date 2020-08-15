class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }
        stack<int> s;
        for (char c : num) {
            while (!s.empty() && k > 0) {
                if (s.top() > c) {
                    s.pop();
                    --k;
                } else {
                    break;
                }
            }
            if (c == '0') {
                if (!s.empty()) {
                    s.push(c);
                }
            } else {
                s.push(c);
            }
        }
        while (!s.empty() && k > 0) {
            s.pop();
            --k;
        }
        if (s.empty()) {
            return "0";
        }
        string rv = "";
        while (!s.empty()) {
            rv.push_back(s.top());
            s.pop();
        }
        reverse(rv.begin(), rv.end());
        return rv;
    }
};