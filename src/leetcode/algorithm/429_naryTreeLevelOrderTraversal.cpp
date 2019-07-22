#include <deque>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> rv;
    deque<Node *> q;
    if (root != nullptr) {
        q.push_back(root);
    }
    while (!q.empty()) {
        size_t size = q.size();
        vector<int> vec(size);
        for (size_t i = 0; i < size; ++i) {
            Node *n = q.front();
            q.pop_front();
            vec[i] = n->val;
            for (Node* cn : n->children) {
                if (cn != nullptr) {
                    q.push_back(cn);
                }
            }
        }
        rv.push_back(vec);
    }
    return rv;
}