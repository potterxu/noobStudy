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

    void insert(T t, int index = -1)
    {
        if (index >= m_length || index == -1) {
            // insert at the end of the list
            index = m_length;
        }
        if (index == 0) {
            m_head = new Node<T>(t, m_head);
            m_length++;
            return;
        }
        Node<T> *pre_ptr = operator[](index - 1);
        pre_ptr->m_nextNode = new Node<T>(t, pre_ptr->m_nextNode);
        m_length++;
    }

    void remove(int index)
    {
        if (index >= m_length) {
            printf("Cannot remove item %d, length of list is %d", index, m_length);
            return;
        }

        m_length--;
        if (index == 0) {
            Node<T> *tmp = m_head;
            m_head = m_head->m_nextNode;
            delete tmp;
            return;
        }

        Node<T> *pre_ptr = operator[](index-1);
        Node<T> *ptrToRemove = pre_ptr->m_nextNode;
        pre_ptr->m_nextNode = ptrToRemove->m_nextNode;
        delete ptrToRemove;
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

    int find(T t)
    {
        Node<T> *ptr = m_head;
        int index = 0;
        while (ptr != nullptr) {
            if (ptr->m_value == t) {
                return index;
            }
            index++;
            ptr = ptr->m_nextNode;
        }
        return -1;
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
    int m_length = 0;
};
}