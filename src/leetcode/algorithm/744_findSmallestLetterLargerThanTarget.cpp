#include<vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    for (char c : letters) {
        if (c > target) {
            return c;
        }
    }
    return letters[0];
}