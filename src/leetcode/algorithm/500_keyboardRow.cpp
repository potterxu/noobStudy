#include <string>
#include <vector>

using namespace std;

vector<string> findWords(vector<string>& words) {
    static string str[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    vector<string> rv;
    for (string word : words) {
        string *ptr = nullptr;
        bool ok = true;
        for (char c : word) {
            if (c < 0x61) {
                c+=0x20;
            }
            if (ptr == nullptr) {
                ptr = &str[0];
                while (ptr->find(c) == string::npos) {
                    ++ptr;
                }
            }
            if (ptr->find(c) == string::npos) {
                ok = false;
                break;
            }
        }
        if (ok) {
            rv.push_back(word);
        }
    }
    return rv;
}