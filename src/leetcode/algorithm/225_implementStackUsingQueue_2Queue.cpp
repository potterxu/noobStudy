#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        _top = x;
        if (empty()) {
            q1.push(x);
        } else if (!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int rv = _top;
        if (!q1.empty()) {
            while (q1.size() > 1) {
                if (q1.size() == 2) {
                    _top = q1.front();
                }
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        } else {
            while (q2.size() > 1) {
                if (q2.size() == 2) {
                    _top = q2.front();
                }
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
        return rv;
    }
    
    /** Get the top element. */
    int top() {
        return _top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (q1.empty() && q2.empty()) {
            return true;
        }
        return false;
    }
    int _top;
    queue<int> q1;
    queue<int> q2;
};