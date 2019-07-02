#include <iostream>
#include <string>

using namespace std;

string defangIPaddr(string address) {
    string out;
    for (auto c : address) {
        if (c == '.') {
            out += "[.]";
        } else {
            out += c;
        }
    }
    return out;
}