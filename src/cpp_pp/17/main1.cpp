#include <iostream>

using namespace std;

int main()
{
    char in;
    int count = 0;
    cin >> in;
    while (in != '$') {
        count++;
        cin >> in;
    }
    cout << count;
    return 0;
}