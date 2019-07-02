#include <string>

using namespace std;

string removeOuterParentheses(string S) {
    int left = 0;
    int right = 0;
    string out;
    for (char c : S) {
        if (c == '(') {
            left++;
            if (left > 1) {
                out += "(";
            }
        } else {
            right++;
            if (right < left) {
                out += ")";
            } else if (right == left) {
                right = left = 0;
            }
        }
    }
    return out;
}