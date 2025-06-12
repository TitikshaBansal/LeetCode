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
    void recurse(TreeNode* root, int val){
        if(root->val > val) {
            if(root->left) return recurse(root->left, val);
            else {
                root->left = new TreeNode(val);
                return;
            }
        }
        if(root->val < val) {
            if(root->right) return recurse(root->right, val);
            else {
                root->right = new TreeNode(val);
                return;
            }
        }

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* head = new TreeNode(val);
            return head;
        }
        recurse(root, val);
        return root;
    }
};

// https://leetcode.com/problems/insert-into-a-binary-search-tree/
