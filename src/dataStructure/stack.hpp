#include <sstream>
#include "node.hpp"

namespace pxu
{
using namespace std;

template <class T>
class Stack
{
public:
    ~Stack()
    {
        clear();
    }

    T top()
    {
        if (m_length <= 0) {
            printf("Stack has no element.\n");
            return -1;
        }
        return m_top->m_value;
    }

    int size()
    {
        return m_length;
    }

    void push(T t)
    {
        Node<T> *ptr = new Node<T>(t, m_top);
        m_top = ptr;
        m_length++;
    }

    void pop()
    {
        if (m_length == 0) {
            printf("No data in stack\n");
            return;
        }
        Node<T> *ptrToRemove = m_top;
        m_top = m_top->m_nextNode;
        delete ptrToRemove;
        m_length--;
        return;
    }

    void print() {
        stringstream ss;
        if (m_length == 0) {
            ss << "Empty stack";
        } else {
            ss << "Length: " << m_length << endl;
            Node<T> *ptr = m_top;
            ss << "(Stack Start" << endl;
            while (1) {
                ss << "{ ";
                ss << ptr->m_value;
                ss << " }";
                ss << endl;
                if (ptr->m_nextNode == nullptr) {
                    break;
                }
                ptr = ptr->m_nextNode;
            }
            ss << "Stack End)" << endl;
        }
        printf("%s\n", ss.str().c_str());
    }

    void clear()
    {
        while (m_length != 0) {
            pop();
        }
    }

private:
    Node<T> *m_top = nullptr;
    int m_length = 0;
};
}