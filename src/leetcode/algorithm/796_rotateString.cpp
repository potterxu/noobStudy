#include <string>
using namespace std;

bool rotateString(string A, string B) {
    if (A.size() != B.size()) {
        return false;
    }
    A += A;
    if (A.find(B) == string::npos) {
        return false;
    }
    return true;
}