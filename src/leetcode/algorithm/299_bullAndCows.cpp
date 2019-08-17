#include <string>
#include <unordered_map>
using namespace std;

string getHint(string secret, string guess) {
    unordered_map<char, int> m;
    int a = 0;
    int b = 0;
    for (int i = 0; i < secret.size(); ++i) {
        if (secret[i] == guess[i]) {
            ++a;
            continue;
        }
        if (m[secret[i]] < 0) {
            ++b;
        } 
        ++m[secret[i]];
        if (m[guess[i]] > 0) {
            ++b;
        }
        --m[guess[i]];
    }
    string rv;
    rv += to_string(a);
    rv.push_back('A');
    rv += to_string(b);
    rv.push_back('B');
    return rv;
}