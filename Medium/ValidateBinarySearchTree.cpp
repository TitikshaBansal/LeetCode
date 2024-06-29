class Solution {
private:
    bool isBST(TreeNode* root, long min, long max) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        bool left = isBST(root->left, min, root->val);
        bool right = isBST(root->right, root->val, max);
        return left && right;
    }

public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
