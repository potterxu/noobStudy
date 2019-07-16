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

template<class T>
class Tree
{
public:
    TreeNode<T> *search(T t)
    {
        return _search(t, m_root);
    }

    void clear()
    {
        _clear(m_root);
        m_root = nullptr;
    }

    // Assume no repeat value
    virtual void insert(T t) = 0;
    virtual void remove(T t) = 0;
    virtual void print() = 0;

    TreeNode<T> *root()
    {
        return m_root;
    }

protected:
    TreeNode<T> *_search(T t, TreeNode<T> *root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (t == root->m_value) {
            return root;
        } else if (t < root->m_value) {
            return _search(t, root->m_left);
        } else {
            return _search(t, root->m_right);
        }
    }

    void _clear(TreeNode<T> *node)
    {
        if (node == nullptr) {
            return;
        }
        _clear(node->m_left);
        _clear(node->m_right);
        delete node;
    }

    TreeNode<T> *m_root = nullptr;
};

template <class T>
class BinarySearchTree : public Tree<T>
{
public:
    BinarySearchTree()
    {
    }

    // Assume no repeat value
    virtual void insert(T t) override
    {
        TreeNode<T> *node = new TreeNode<T>(t);
        if (m_root == nullptr) {
            m_root = node;
            return;
        }
        _insert(node, m_root, nullptr);
    }

    virtual void remove(T t) override
    {
        TreeNode<T> *ptr = search(t);
        _remove(ptr, &m_root);
    }

    virtual void print() override
    {
        _print(m_root);
    }

protected:
    void _insert(TreeNode<T> *node, TreeNode<T> *root, TreeNode<T> *parent)
    {
        if (root == nullptr) {
            node->m_parent = parent;
            if (node->m_value < parent->m_value) {
                parent->m_left = node;
            } else {
                parent->m_right = node;
            }
            return;
        }
        if (node->m_value < root->m_value) {
            _insert(node, root->m_left, root);
        } else if (node->m_value > root->m_value) {
            _insert(node, root->m_right, root);
        } else {
            delete node;
            return;
        }
    }

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

    void _print(TreeNode<T> *node)
    {
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
};
}