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
void process(Node* root, vector<int> &vec) {
    if (root == nullptr) {
        return;
    }

    for(auto n : root->children) {
        process(n, vec);
    }
    vec.push_back(root->val);
}

vector<int> postorder(Node* root) {
    vector<int> vec;
    process(root, vec);
    return vec;
}
