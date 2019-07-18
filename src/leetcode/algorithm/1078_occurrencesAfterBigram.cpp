#include <string>
#include <vector>

using namespace std;

vector<string> findOcurrences(string text, string first, string second) {
    vector<string> rv;
    int count = 0;
    int startI = 0;
    while (startI < text.size()) {
        int i = startI;
        while (i < text.size()) {
            if (text[i] == ' '){
                break;
            }
            ++i;
        }
        string s = text.substr(startI, i - startI);
        if (count == 2) {
            rv.push_back(s);
            count = 0;
        }
        if (s == first) {
            count = 1;
        } else if (count == 1 && s == second) {
            count = 2;
        } else {
            count = 0;
        }
        startI = i + 1;
    }
    return rv;
}