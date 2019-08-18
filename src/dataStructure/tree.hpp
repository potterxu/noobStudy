#include <iostream>
#include <sstream>

namespace pxu
{
static inline int max(int a, int b)
{
    return a > b ? a : b;
}

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
    int m_height = 0;
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
    void insert(T t) override
    {
        TreeNode<T> *node = new TreeNode<T>(t);
        this->m_root = _insert(this->m_root, node);
    }

    void remove(T t) override
    {
        _remove(this->m_root, t);
    }

    void print() override
    {
        _print(this->m_root);
    }

protected:
    virtual TreeNode<T> *_insert(TreeNode<T> *root, TreeNode<T> *node)
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

    TreeNode<T> *_min(TreeNode<T> *root)
    {
        while (root->m_left != nullptr) {
            root = root->m_left;
        }
        return root;
    }

    virtual TreeNode<T> *_remove(TreeNode<T>* root, T t)
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
                newRoot->m_right = this->m_root->m_right;
                delete root;
                return newRoot;
            }
        }
        return root;
    }

    virtual void _print(TreeNode<T> *node)
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

template <class T>
class AVLTree : public BinarySearchTree<T>
{
public:
    AVLTree()
    : BinarySearchTree<T>()
    {

    }
protected:
    int _height(TreeNode<T> *root)
    {
        return root == nullptr ? -1 : root->m_height;
    }

    void _updateHeight(TreeNode<T> *root)
    {
        root->m_height = max(_height(root->m_left), _height(root->m_right)) + 1;
    }

    TreeNode<T> *_llRotate(TreeNode<T> *root)
    {
        TreeNode<T> *newRoot = root->m_left;
        root->m_left = newRoot->m_right;
        newRoot->m_right = root;
        _updateHeight(root);
        _updateHeight(newRoot);
        return newRoot;
    }

    TreeNode<T> *_lrRotate(TreeNode<T> *root)
    {
        root->m_left = _rrRotate(root->m_left);
        return _llRotate(root);
    }

    TreeNode<T> *_rrRotate(TreeNode<T> *root)
    {
        TreeNode<T> *newRoot = root->m_right;
        root->m_right = newRoot->m_left;
        newRoot->m_left = root;
        _updateHeight(root);
        _updateHeight(newRoot);
        return newRoot;
    }

    TreeNode<T> *_rlRotate(TreeNode<T> *root)
    {
        root->m_right = _llRotate(root->m_right);
        return _rrRotate(root);
    }

    TreeNode<T> *_insert(TreeNode<T> *root, TreeNode<T> *node) override
    {
        printf("AVL insert\n");
        if (root == nullptr) {
            return node;
        }
        int lH = _height(root->m_left);
        int rH = _height(root->m_right);
        if (node->m_value < root->m_value) {
            root->m_left = _insert(root->m_left, node);
            lH = _height(root->m_left);
            printf("%d %d\n", lH, rH);
            if (lH - rH == 2) {
                if (node->m_value < root->m_left->m_value) {
                    root = _llRotate(root);
                } else if (node->m_value > root->m_left->m_value) {
                    root =_lrRotate(root);
                }
            }
        } else if (node->m_value > root->m_value) {
            root->m_right = _insert(root->m_right, node);
            rH = _height(root->m_right);
            printf("%d %d\n", lH, rH);
            if (rH - lH == 2) {
                if (node->m_value < root->m_right->m_value) {
                    root = _rlRotate(root);
                } else if (node->m_value > root->m_right->m_value) {
                    root = _rrRotate(root);
                }
            }
        }
        _updateHeight(root);
        return root;
    }

    TreeNode<T> *_remove(TreeNode<T> *root, T t) override
    {
        if (root == nullptr) {
            return root;
        }

        int lH = _height(root->m_left);
        int rH = _height(root->m_right);
        if (t < root->m_value) {
            root->m_left = _remove(root->m_left, t);
            lH = _height(root->m_left);
            if (lH - rH == 2) {
                if (t < root->m_left->m_value) {
                    _llRotate(root);
                } else if (t > root->m_left->m_value) {
                    _lrRotate(root);
                }
            }
        } else if (t > root->m_value) {
            root->m_right = _remove(root->m_right, t);
            rH = _height(root->m_right);
            if (rH - lH == 2) {
                if (t < root->m_right->m_value) {
                    _rlRotate(root);
                } else if (t > root->m_right->m_value) {
                    _rrRotate(root);
                }
            }
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
                newRoot->m_right = this->m_root->m_right;
                delete root;
                return newRoot;
            }
        }
        _updateHeight(root);
        return root;
    }

    void _print(TreeNode<T> *root) override
    {
        std::stringstream ss;
        if (root == nullptr) {
            ss << "{}, ";
            printf("%s ", ss.str().c_str());
            return;
        } else {
            ss << "{" << root->m_value << ", " << root->m_height << "}, ";
        }
        printf("%s ", ss.str().c_str());
        _print(root->m_left);
        _print(root->m_right);
    }
};
}