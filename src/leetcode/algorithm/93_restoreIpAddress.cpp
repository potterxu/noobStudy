#include <string>
#include <vector>
using namespace std;

bool isValidNumber(string &s, int start, int end) {
    if (end != start && s[start] == '0') {
        return false;
    }
    int num = 0;
    for (int i = start; i <= end; ++i) {
        num *= 10;
        num += s[i] - '0';
    }
    if (num > 255) {
        return false;
    }
    return true;
}
vector<string> restoreIpAddresses(string s) {
    vector<string> rv;
    for (int i = 0; i < 3 && i < s.size() - 3; ++i) {
        //printf("%d\n", i);
        if (!isValidNumber(s, 0, i)) {
            break;
        }
        if (s.size() - 1 - i > 9) {
            continue;
        }
        for (int j = i + 1; j < s.size() - 2 && j < i + 4; ++j) {
            //printf("%d, %d\n", i, j);
            if (!isValidNumber(s, i + 1, j)) {
                break;
            }
            if (s.size() - 1 - j > 6) {
                continue;
            }
            for (int k = j + 1; k < s.size() - 1 && k < j + 4; ++k) {
                //printf("%d, %d, %d\n", i, j, k);
                if (!isValidNumber(s, j + 1, k)) {
                    break;
                }
                if (s.size() - 1 - k > 3) {
                    continue;
                }
                if (!isValidNumber(s, k + 1, s.size() - 1)) {
                    continue;
                }
                //printf("yes\n");
                string str;
                str += s.substr(0, i + 1);
                str.push_back('.');
                str += s.substr(i + 1, j - i);
                str.push_back('.');
                str += s.substr(j + 1, k - j);
                str.push_back('.');
                str += s.substr(k + 1, s.size() - k);
                rv.push_back(str);
            }
        }
    }
    return rv;
}