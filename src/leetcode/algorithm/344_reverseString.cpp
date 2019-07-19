#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int front = 0, end = s.size() - 1;
    while (front < end) {
        swap(s[front], s[end]);
        front++;
        end--;
    }
}