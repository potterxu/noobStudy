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

    T m_value;
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
        m_root = _insert(m_root, node);
    }

    virtual void remove(T t) override
    {
        _remove(m_root, t);
    }

    virtual void print() override
    {
        _print(m_root);
    }

protected:
    TreeNode<T> *_insert(TreeNode<T> *root, TreeNode<T> *node)
    {
        if (root == nullptr) {
            return node;
        }
        if (node->m_value < root->m_value) {
            root->m_left = _insert(root->m_left, node);
        } else if (node->m_value > root->m_value) {
            root->m_right = _insert(root->m_right, node);
        } else {
            delete node;
        }
        return root;
    }

    TreeNode<T> *_max(TreeNode<T> *root)
    {
        while (root->m_right != nullptr) {
            root = root->m_right;
        }
        return root;
    }

    TreeNode<T> *_min()
    {
        while (root->m_left != nullptr) {
            root = root->m_left;
        }
        return root;
    }

    TreeNode<T> *_remove(TreeNode<T>* root, T t)
    {
        if (root == nullptr) {
            return root;
        }

        if (t < root->m_value) {
            root->m_left = _remove(root->m_left, t);
        } else if (t > root->m_value) {
            root->m_right = _remove(root->m_right, t);
        } else if (t == root->m_value) {
            if (root->m_left == nullptr && root->m_right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->m_left != nullptr && root->m_right == nullptr) {
                delete root;
                return root->m_left;
            } else if (root->m_left == nullptr && root->m_right != nullptr) {
                delete root;
                return root->m_right;
            } else {
                TreeNode<T> *newRoot = root->m_left;
                newRoot->m_left = _remove(root->m_left, newRoot->m_value);
                newRoot->m_right = m_root->m_right;
                delete root;
                return newRoot;
            }
        }
        return root;
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