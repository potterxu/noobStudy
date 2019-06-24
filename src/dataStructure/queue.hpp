#include "node.hpp"
#include <sstream>

namespace pxu
{
using namespace std;

template <class T>
class Queue
{
public:
    ~Queue()
    {
        clear();
    }

    void push(T t)
    {
        if (m_length == 0) {
            m_front = m_end = new Node<T>(t);
        } else {
            m_end->m_nextNode = new Node<T>(t);
            m_end = m_end->m_nextNode;
        }
        m_length++;
    }

    void pop()
    {
        if (m_length <= 0) {
            printf("Cannot pop on empty queue.\n");
            return;
        }
        Node<T> *ptrToRemove = m_front;
        m_front = m_front->m_nextNode;
        m_length--;
        if (m_length == 0) {
            m_end = nullptr;
        }
    }
    T front()
    {
        if (m_length > 0) {
            return m_front->m_value;
        }
        printf("Queue has no element.\n");
        return -1;
    }

    void clear()
    {
        while (m_length > 0) {
            pop();
        }
    }

    int size()
    {
        return m_length;
    }

    void print()
    {
        stringstream ss;
        if (m_length == 0) {
            ss << "Empty Queue";
        } else {
            Node<T> *ptr = m_front;
            ss << "[ ";
            while (ptr != nullptr) {
                ss << "{ ";
                ss << ptr->m_value;
                ss << " }";
                if (ptr != m_end) {
                    ss << ", ";
                }
                ptr = ptr->m_nextNode;
            }
            ss << " ]";
        }
        printf("%s\n", ss.str().c_str());
    }
private:
    Node<T> *m_front = nullptr;
    Node<T> *m_end = nullptr;
    int m_length = 0;
};
}