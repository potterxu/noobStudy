#include <string>
using namespace std;
bool judgeCircle(string moves) {
    int moveUp = 0, moveLeft = 0;
    for (char c : moves) {
        switch (c) {
            case 'U':
                moveUp++;
                break;
            case 'D':
                moveUp--;
                break;
            case 'L':
                moveLeft++;
                break;
            case 'R':
                moveLeft--;
                break;
            default:
                break;
        }
    }
    if (moveUp == 0 && moveLeft == 0) {
        return true;
    } else {
        return false;
    }
}