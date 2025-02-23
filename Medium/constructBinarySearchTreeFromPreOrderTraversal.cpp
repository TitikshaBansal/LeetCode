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
    int preIndex = 0;

    TreeNode* buildBST(vector<int>& preorder, int bound) {
        if (preIndex >= preorder.size() || preorder[preIndex] > bound) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildBST(preorder, rootVal);
        root->right = buildBST(preorder, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, INT_MAX);
    }
};

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
