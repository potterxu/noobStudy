#include <string>
using namespace std;

int repeatedStringMatch(string A, string B) {
    int rv = 1;
    string newA = A;
    while (newA.size() <= B.size() + A.size() + A.size()) {
        if(newA.find(B) != string::npos) {
            return rv;
        }
        newA += A;
        ++rv;
    }
    return -1;
}