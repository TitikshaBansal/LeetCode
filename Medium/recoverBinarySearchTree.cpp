class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *curr = root, *prev = nullptr;
        TreeNode *first = nullptr, *second = nullptr;

        while (curr) {
            if (!curr->left) {
                // Check for violation
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;

                    // Check for violation
                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // Swap the values of the two nodes
        if (first && second)
            swap(first->val, second->val);
    }
};


// https://leetcode.com/problems/recover-binary-search-tree/
