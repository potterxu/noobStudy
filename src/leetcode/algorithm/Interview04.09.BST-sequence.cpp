/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<list<int>> mergeListFromIt (list<int> &a, list<int> b, list<int>::iterator it) {
        vector<list<int>> rv;
        if (b.empty()) {
            rv.push_back(a);
            return rv;
        }
        rv.push_back(a);
        auto &tmp = rv.back();
        tmp.insert(tmp.end(), b.begin(), b.end());
        
        int toInsert = b.front();
        b.erase(b.begin());

        while (it != a.end()) {
            list<int> tmp = a;
            auto tmpIt = find(tmp.begin(), tmp.end(), *it);
            
            tmpIt = tmp.insert(tmpIt, toInsert);
                    
            ++tmpIt;

            auto innerResult = mergeListFromIt(tmp, b, tmpIt);

            ++it;

            rv.insert(rv.end(), innerResult.begin(), innerResult.end());
        }

        return rv;
    }
    void mergeList(list<int> &a, list<int> &b, vector<list<int>> &result) {


        auto tmp = mergeListFromIt(a, b, a.begin());
        result.insert(result.end(), tmp.begin(), tmp.end());
    }
    void merge(vector<list<int>> &a, vector<list<int>> &b, vector<list<int>> &result) {
        if (a.empty() && b.empty()) {
            return;
        }
        if (a.empty() && !b.empty()) {
            result.insert(result.end(), b.begin(), b.end());
            return;
        }
        if (!a.empty() && b.empty()) {
            result.insert(result.end(), a.begin(), a.end());
            return;
        }
        // merge a and b and keep the original sequence in a and b
        for (auto &al : a) {
            for (auto &bl : b) {
                mergeList(al, bl, result);
            }
        }
    }

    void process(TreeNode *root, vector<list<int>> &lists) {
        if (!root) {
            return;
        }
        vector<list<int>> left;
        vector<list<int>> right;
        process(root->left, left);
        process(root->right, right);
        merge(left, right, lists);
        for (auto &l : lists) {
            l.insert(l.begin(), root->val);
        }
        if (lists.empty()) {
            list<int> tmp;
            tmp.push_back(root->val);
            lists.push_back(tmp);
        }
    }
    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<list<int>> lists;
        process(root, lists);
        vector<vector<int>> rv(lists.size());
        for (int i = 0; i < lists.size(); ++i) {
            rv[i] = vector<int> (lists[i].begin(), lists[i].end());
        }
        if (rv.empty()) {
            rv.push_back(vector<int>());
        }
        return rv;
    }
};