#include <string>
using namespace std;

string convertToBase7(int num) {
    static int base[9] {5764801, 823543, 117649, 16807, 2401, 343, 49, 7, 1};
    string rv;
    if (num < 0) {
        num = -num;
        rv.push_back('-');
    } else if (num == 0){
        return "0";
    }
    for (int i = 0; i < 9; ++i) {
        int c = 0;
        while (num >= base[i]) {
            num -= base[i];
            ++c;
        }
        if (c) {
            rv += to_string(c);
        }  else {
            if (!rv.empty() && rv != "-") {
                rv += to_string(c);
            }
        }
    }
    return rv;
}