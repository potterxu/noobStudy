#include <string>
using namespace std;

string toLowerCase(string str) {
    for (auto &c : str) {
        if (0x41 <= c && c <= 0x5A) {
            c += 0x20;
        }
    }
    return str;
}