#include <stack>
#include <string>
#include <vector>
using namespace std;

int calPoints(vector<string>& ops) {
    stack<int> q;
    for (string c : ops) {
        if (c == "C") {
            q.pop();
        } else if (c == "D") {
            q.push(q.top() + q.top());
        } else if (c == "+") {
            int last = q.top();
            q.pop();
            int lastlast = q.top();
            q.push(last);
            q.push(last + lastlast);
        } else {
            q.push(stoi(c));
        }
    }
    int sum = 0;
    while (!q.empty()) {
        sum += q.top();
        q.pop();
    }
    return sum;
}