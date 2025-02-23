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
    TreeNode* construct(int& preIndex, int& postIndex, vector<int>& preorder, vector<int>& postorder){
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if(root->val != postorder[postIndex]) root->left = construct(preIndex, postIndex, preorder, postorder);
        if(root->val != postorder[postIndex]) root->right = construct(preIndex, postIndex, preorder, postorder);
        postIndex++;
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex =0, postIndex =0;
        return construct(preIndex, postIndex, preorder, postorder);
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/?envType=daily-question&envId=2025-02-23
