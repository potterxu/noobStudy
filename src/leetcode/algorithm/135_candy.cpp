#include <vector>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int sumToN(int n) {
    return (1+n) * n / 2;
}

int process(vector<int>& ratings, int start, int end, int peak) {
    // process a up and down mountain [a, b)
    return sumToN(peak - start) + sumToN(end - peak) + max(peak-start, end-peak)+1;
}

int getInc(int pre, int after) {
    if (pre > after) {
        return -1;
    } else if (pre < after) {
        return 1;
    }
    return 0;
}

int candy(vector<int>& ratings) {
    if (ratings.empty()) {
        return 0;
    } else if (ratings.size() == 1) {
        return 1;
    } else if (ratings.size() == 2) {
        if (ratings[0] == ratings[1]) {
            return 2;
        } else {
            return 3;
        }
    }
    // find all individual mountain
    int sum = 0;
    int start = 0;
    int end = 1;
    int peak = 0;
    int inc = -2; // invalid
    while (end < ratings.size()) {
        int curInc = getInc(ratings[end-1], ratings[end]);
        if (curInc == inc) {
            if (inc == 0) {
                ++sum;
                start = end;
                peak = start;
            } else if (inc == 1) {
                peak = end;
            }
        } else {
            if (inc == -1) {
                sum += process(ratings, start, end - 1, peak);
                if (curInc == 1) {
                    --sum;
                    start = end - 1;
                } else {
                    start = end;
                }
                peak = start;
            } else if (inc == 0) {
                start = end - 1;
                peak = start;
            } else if (inc == 1){
                peak = end - 1;
                if (curInc == 0) {
                    sum += process(ratings, start, end - 1, peak);
                    start = end;
                    peak = start;
                }
            } else {
                if (curInc == 0) {
                    ++sum;
                }
                start = end - 1;
            }
            inc = curInc;
        }
        ++end;
    }
    sum += process(ratings, start, end - 1, peak);
    return sum;
}