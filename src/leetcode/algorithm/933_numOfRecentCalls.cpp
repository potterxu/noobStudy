#include <deque>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        m_queue.push_back(t);
        while (m_queue.front() < t - 3000) {
            m_queue.pop_front();
        }
        return m_queue.size();
    }
protected:
    deque<int> m_queue;
};