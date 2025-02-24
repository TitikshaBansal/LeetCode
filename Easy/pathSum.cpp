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
    bool solve(TreeNode* root, int targetSum, int currSum){
        if (!root) return false;
        currSum += root->val;
        if (!root->left && !root->right) return currSum == targetSum;
        return solve(root->left, targetSum, currSum) || solve(root->right, targetSum, currSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return solve(root, targetSum, 0);
    }
};

// https://leetcode.com/problems/path-sum/
