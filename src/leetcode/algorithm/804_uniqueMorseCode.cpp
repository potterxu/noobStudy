#include <set>
#include <string>
#include <vector>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    string msArr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    set<string> s;
    for (string str : words) {
        string ms;
        for (char c : str) {
            ms += msArr[c - 'a'];
        }
        s.insert(ms);
    }
    return s.size();
}