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
private:
    pair<int, int> solve(TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int height = 1 + max(left.first, right.first);
        int dia = left.first + right.first;
        int maxDia = max({left.second, right.second, dia});

        return {height, maxDia};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).second;
    }
};

// https://leetcode.com/problems/diameter-of-binary-tree/
