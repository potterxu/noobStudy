#include <vector>

using namespace std;

int numRookCaptures(vector<vector<char>>& board) {
    int rv, rx, ry;
    rv = rx = ry = 0;
    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[y].size(); ++x) {
            if (board[y][x] == 'R') {
                rx = x;
                ry = y;
                break;
            }
        }
    }

    for (int i = rx - 1; i > 0; --i) {
        if (board[ry][i] == 'p') {
            rv++;
            break;
        } else if (board[ry][i] == 'B') {
            break;
        }
    }

    for (int i = rx + 1; i < board.size(); ++i) {
        if (board[ry][i] == 'p') {
            rv++;
            break;
        } else if (board[ry][i] == 'B') {
            break;
        }
    }

    for (int i = ry - 1; i > 0; --i) {
        if (board[i][rx] == 'p') {
            rv++;
            break;
        } else if (board[i][rx] == 'B') {
            break;
        }
    }

    for (int i = ry + 1; i < board.size(); ++i) {
        if (board[i][rx] == 'p') {
            rv++;
            break;
        } else if (board[i][rx] == 'B') {
            break;
        }
    }
    return rv;
}