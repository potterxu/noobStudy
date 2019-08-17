#include <deque>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        q.push_back(x);
        m = min(x, m);
    }
    
    void pop() {
        int v = q.back();
        q.pop_back();
        if (m == v) {
            m = 0x7fffffff;
            for (int i : q) {
                m = min(i, m);
            }
        }
    }
    
    int top() {
        return q.back();
    }
    
    int getMin() {
        return m;
    }
    
    int m = 0x7fffffff;
    deque<int> q;
};