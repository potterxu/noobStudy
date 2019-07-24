#include <string>
#include <vector>
using namespace std;

bool isChar(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<int> logStart(logs.size());
    for (size_t i = 0; i < logs.size(); ++i) {
        logStart[i] = logs[i].find(' ') + 1;
        if (isChar(logs[i][logStart[i]])) {
            int pivot = i;
            while (pivot > 0) {
                if(!isChar(logs[pivot - 1][logStart[pivot - 1]])) {
                    swap(logs[pivot - 1], logs[pivot]);
                    swap(logStart[pivot - 1], logStart[pivot]);
                } else {
                    int j = logStart[pivot];
                    int k = logStart[pivot - 1];
                    bool needSwap = false;
                    while (j < logs[pivot].size() && k < logs[pivot-1].size()) {
                        if (logs[pivot][j] < logs[pivot-1][k]) {
                            needSwap = true;
                            break;
                        } else if (logs[pivot][j] > logs[pivot-1][k]) {
                            break;
                        }
                        ++j;
                        ++k;
                    }
                    if (!needSwap) {
                        if (j == logs[pivot].size()) {
                            needSwap = true;
                        }
                    }
                    if (needSwap) {
                        swap(logs[pivot - 1], logs[pivot]);
                        swap(logStart[pivot - 1], logStart[pivot]);
                    } else {
                        break;
                    }
                }
                --pivot;
            }
        }
    }
    return logs;
}