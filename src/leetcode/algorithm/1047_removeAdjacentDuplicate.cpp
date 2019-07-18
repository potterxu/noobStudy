#include <deque>
#include <string>

using namespace std;

string removeDuplicates(string S) {
    deque<char> q;
    for (auto c : S) {
        if (q.empty()) {
            q.push_back(c);
            continue;
        }
        if (q.back() == c) {
            q.pop_back();
        } else {
            q.push_back(c);
        }
    }
    string rv;
    while (!q.empty()) {
        rv += q.front();
        q.pop_front();
    }
    return rv;
}