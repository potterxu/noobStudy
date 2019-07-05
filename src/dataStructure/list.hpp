#include <sstream>
#include "node.hpp"

namespace pxu
{
using namespace std;

template <class T>
class LinkedList
{
public:
    ~LinkedList()
    {
        clear();
    }

    T head()
    {
        if (m_length <= 0) {
            printf("List has no element.\n");
            return -1;
        }
        return m_head->m_value;
    }

    T end()
    {
        if (m_length <= 0) {
            printf("List has no element.\n");
            return -1;
        }
        return m_end->m_value;
    }

    void push_back(T t)
    {
        if (m_length == 0) {
            m_head = m_end = new Node<T>(t);
        } else {
            m_end->m_nextNode = new Node<T>(t);
            m_end = m_end->m_nextNode;
        }
        m_length++;
    }

    void remove(int index)
    {
        if (index >= m_length) {
            printf("Cannot remove item %d, length of list is %d", index, m_length);
            return;
        }

        Node<T> *pre_ptr = nullptr;
        Node<T> *toBeRemove;
        if (index == 0) {
            toBeRemove = m_head;
            m_head = m_head->m_nextNode;
        } else {
            pre_ptr = operator[](index-1);
            toBeRemove = pre_ptr->m_nextNode;
            pre_ptr->m_nextNode = toBeRemove->m_nextNode;
        }

        if (index == m_length - 1) {
            m_end = pre_ptr;
        }
        m_length--;
        delete toBeRemove;
    }

    void clear()
    {
        while (m_length > 0) {
            remove(0);
        }
    }

    Node<T> *operator[](int index)
    {
        if (index >= m_length) {
            printf("Cannot get item %d, list has length of %d", index, m_length);
            return nullptr;
        }
        Node<T> *ptr = m_head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->m_nextNode;
        }
        return ptr;
    }

    void print()
    {
        stringstream ss;
        if (m_length == 0) {
            ss << "empty list";
        } else {
            ss << "Length " << m_length << " ";
            Node<T> *ptr = m_head;
            while (1) {
                ss << "{ ";
                ss << ptr->m_value;
                ss << " }";
                if (ptr->m_nextNode == nullptr) {
                    break;
                }
                ss << " -> ";
                ptr = ptr->m_nextNode;
            }
        }
        printf("%s\n", ss.str().c_str());
    }

    int size()
    {
        return m_length;
    }

private:

    Node<T> *m_head = nullptr;
    Node<T> *m_end = nullptr;
    int m_length = 0;
};
}