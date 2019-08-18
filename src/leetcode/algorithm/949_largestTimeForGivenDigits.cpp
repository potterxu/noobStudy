#include <string>
#include <vector>
using namespace std;

string largestTimeFromDigits(vector<int>& A) {
    int a[4] = {-1, -1, -1, -1};
    for (int i = 0; i < 4; ++i) {
        if (A[i] > 2) {
            continue;
        }
        for (int j = 0; j < 4; ++j) {
            if (j != i) {
                if (A[i] == 2 && A[j] > 3) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    if (A[k] > 5) {
                        continue;
                    }
                    if (k != j && k != i) {
                        int l = 6 - i - j - k;
                        bool larger = false;
                        if (a[0] == -1) {
                            larger = true;
                        } else if (A[i] > a[0]) {
                            larger = true;
                        } else if (A[i] == a[0]) {
                            if (A[j] > a[1]) {
                                larger = true;
                            } else if (A[j] == a[1]) {
                                if (A[k] > a[2]) {
                                    larger = true;
                                } else if (A[k] == a[2]) {
                                    if (A[l] > a[3]) {
                                        larger = true;
                                    }
                                }
                            }
                        }
                        if (larger) {
                            a[0] = A[i];
                            a[1] = A[j];
                            a[2] = A[k];
                            a[3] = A[l];
                        }
                    }
                }
            }
        }
    }
    if (a[0] == -1) {
        return "";
    }
    string rv = "  :  ";
    rv[0] = a[0] + '0';
    rv[1] = a[1] + '0';
    rv[3] = a[2] + '0';
    rv[4] = a[3] + '0';
    return rv;
}