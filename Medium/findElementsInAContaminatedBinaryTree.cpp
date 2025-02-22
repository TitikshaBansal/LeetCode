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
class FindElements {
private: 
    void helper(TreeNode* root){
        if(root == nullptr) return;
        if(root->left){
            root->left->val = 2*root->val+1;
            helper(root->left);
        }
        if(root->right){
            root->right->val = 2*root->val+2;
            helper(root->right);
        }
    }
    bool found(int target, TreeNode* root){
        if(root == nullptr) return false;
        if(root->val == target) return true;

        bool left = found(target, root->left);
        bool right = found(target, root->right);
        return left|right;
    }
public:
    TreeNode* temp;
    FindElements(TreeNode* root) {
        root->val =0;
        helper(root);
        temp = root;
    }
    
    bool find(int target) {
        return found(target, temp);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/?envType=daily-question&envId=2025-02-21
