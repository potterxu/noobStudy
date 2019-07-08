#include <iostream>
#include <sstream>

namespace pxu
{
template <class T>
class TreeNode
{
public:
    TreeNode(T t)
    : m_value(t)
    {
    }

    T m_value = 0;
    TreeNode<T> *m_parent = nullptr;
    TreeNode<T> *m_left = nullptr;
    TreeNode<T> *m_right = nullptr;
};

template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree()
    {

    }
    TreeNode<T> *search(T t)
    {
        TreeNode<T> *ptr = m_root;
        if (ptr == nullptr) {
            ptr = m_root;
        }
        while (ptr != nullptr) {
            if (t < ptr->m_value) {
                ptr = ptr->m_left;
            } else if (t > ptr->m_value) {
                ptr = ptr->m_right;
            } else {
                break;
            }
        }
        return ptr;
    }

    // Assume no repeat value
    void insert(T t) {
        TreeNode<T> *node = new TreeNode<T>(t);
        if (m_root == nullptr) {
            m_root = node;
            return;
        }

        TreeNode<T> *parent = m_root;
        while(parent != nullptr) {
            if (t < parent->m_value) {
                if (parent->m_left == nullptr) {
                    parent->m_left = node;
                    break;
                } else {
                    parent = parent->m_left;
                }
            } else if (t > parent->m_value) {
                if (parent->m_right == nullptr) {
                    parent->m_right = node;
                    break;
                } else {
                    parent = parent->m_right;
                }
            } else {
                delete node;
                return;
            }
        }
        node->m_parent = parent;
    }

    void clear() {
        _clear(m_root);
        m_root = nullptr;
    }

    void print() {
        _print(m_root);
    }

    void remove(T t) {
        TreeNode<T> *ptr = search(t);
        _remove(ptr, &m_root);
    }

    TreeNode<T> *root() {
        return m_root;
    }

protected:
    void _remove(TreeNode<T> *ptr, TreeNode<T> **root)
    {
        if (ptr == nullptr) {
            return;
        }

        TreeNode<T> *newPtr = nullptr;
        if (ptr->m_left == nullptr && ptr->m_right == nullptr) {
            newPtr = nullptr;
        } else if (ptr->m_left == nullptr && ptr->m_right != nullptr) {
            newPtr = ptr->m_right;
            newPtr->m_parent = ptr->m_parent;
        } else if (ptr->m_left != nullptr && ptr->m_right == nullptr) {
            newPtr = ptr->m_left;
            newPtr->m_parent = ptr->m_parent;
        } else if (ptr->m_left != nullptr && ptr->m_right != nullptr) {
            TreeNode<T> *leftMax = ptr->m_left;
            while (leftMax->m_right != nullptr) {
                leftMax = leftMax->m_right;
            }
            newPtr = new TreeNode<T>(leftMax->m_value);
            newPtr->m_parent = ptr->m_parent;
            newPtr->m_left = ptr->m_left;
            ptr->m_left->m_parent = newPtr;
            newPtr->m_right = ptr->m_right;
            ptr->m_right->m_parent = newPtr;
            _remove(leftMax, &ptr->m_left);
        }
        if (ptr->m_parent != nullptr) {
            if (ptr->m_value > ptr->m_parent->m_value) {
                ptr->m_parent->m_right = newPtr;
            } else {
                ptr->m_parent->m_left = newPtr;
            }
        } else {
            *root = newPtr;
        }
        delete ptr;
    }
    void _clear(TreeNode<T> *node) {
        if (node == nullptr) {
            return;
        }
        _clear(node->m_left);
        _clear(node->m_right);
        delete node;
    }

    void _print(TreeNode<T> *node) {
        std::stringstream ss;
        if (node == nullptr) {
            ss << "{}, ";
            printf("%s ", ss.str().c_str());
            return;
        } else {
            ss << "{" << node->m_value << "}, ";
        }
        printf("%s ", ss.str().c_str());
        _print(node->m_left);
        _print(node->m_right);
    }

    TreeNode<T> *m_root = nullptr;
};
}