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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        bool dir = true;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> curr;
            if(dir){
                for(int i=0; i<n; i++){
                    TreeNode* node = q.front();
                    q.pop_front();
                    curr.push_back(node->val);
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                }
                dir = false;
            }
            else{
                for(int i=0; i<n; i++){
                    TreeNode* node = q.back();
                    q.pop_back();
                    curr.push_back(node->val);
                    if(node->right) q.push_front(node->right);
                    if(node->left) q.push_front(node->left);
                }
                dir = true;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};


// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
