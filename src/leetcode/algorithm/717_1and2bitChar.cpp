#include <vector>
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
    for (int i = 0; i < bits.size() - 1; ++i) {
        if (bits[i] == 1) {
            if (i + 1 == bits.size() - 1) {
                return false;
            }
            ++i;
        }
    }
    return true;
}