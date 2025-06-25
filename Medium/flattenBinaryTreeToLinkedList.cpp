class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
