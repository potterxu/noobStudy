    // O(N) time and O(1) space to loop a tree
    void morris(TreeNode *root) {
        TreeNode *cur = root;
        TreeNode *mostRight = nullptr;
        while (cur != nullptr) {
            mostRight = cur->left;
            if (mostRight != nullptr) {
                while (mostRight->right != nullptr && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == nullptr) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    mostRight->right = nullptr;
                }
            } else {
                // no left tree
            }
            cur = cur->right;
        }
    }