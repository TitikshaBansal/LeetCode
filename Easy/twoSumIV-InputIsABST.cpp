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
    bool inorder(TreeNode* root, int k, unordered_set<int>& s){
        if(!root) return false;
        bool left = inorder(root->left, k, s);
        if(s.count(k-root->val)) return true;
        s.insert(root->val);
        bool right = inorder(root->right, k, s);
        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return inorder(root, k, s);
    }
};

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
