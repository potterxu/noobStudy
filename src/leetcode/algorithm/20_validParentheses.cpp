#include <stack>
#include <string>
using namespace std;
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            if (c > st.top() && c - st.top() < 3) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    if (!st.empty()) {
        return false;
    }
    return true;
}