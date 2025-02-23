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
    unordered_map<int, int> inorderMap; 
    int postIndex;

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int inorderIndex = inorderMap[rootVal];
        root->right = buildTreeHelper(inorder, postorder, inorderIndex + 1, right);
        root->left = buildTreeHelper(inorder, postorder, left, inorderIndex - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIndex = n - 1; 
        for (int i = 0; i < n; i++) inorderMap[inorder[i]] = i;
        return buildTreeHelper(inorder, postorder, 0, n - 1);
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
