/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = 0;

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Info helper(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info left = helper(root->left);
        Info right = helper(root->right);

        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum); 
            return {true, currSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};

// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
