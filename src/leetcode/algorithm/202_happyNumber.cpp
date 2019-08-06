#include <unordered_map>
using namespace std;

bool isHappy(int n) {
    unordered_map<int,int> s;
    while (n != 1) {
        int number = n;
        n = 0;
        while (number != 0) {
            n += pow(number % 10, 2);
            number /= 10;
        }
        if (s.find(n) != s.end()) {
            return false;
        }
        s[n] = 1;
    }
    return true;
}