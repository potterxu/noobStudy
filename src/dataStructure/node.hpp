#ifndef NODE_HPP
#define NODE_HPP
namespace pxu
{
template <class T>
class Node
{
public:
    Node(T t, Node<T> *nextNode = nullptr)
    : m_value(t)
    , m_nextNode(nextNode)
    {
    }

    T m_value;
    Node<T> *m_nextNode;
};
}
#endif