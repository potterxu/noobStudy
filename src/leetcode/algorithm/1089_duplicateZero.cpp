#include <deque>
#include <vector>
using namespace std;

void duplicateZeros(vector<int>& arr) {
    deque<int> q;
    for (int i : arr) {
        q.push_back(i);
        if (i == 0) {
            q.push_back(0);
        }
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = q.front();
        q.pop_front();
    }
}