#include <string>
using namespace std;
int findLUSlength(string a, string b) {
    if (a == b) {
        return -1;
    } else {
        return a.size() > b.size() ? a.size() : b.size();
    }
}