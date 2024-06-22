class Solution {
private:
    void travel(TreeNode* root, vector<int> &v){
        if(root == nullptr) return;
        
        travel(root->left, v);
        v.push_back(root->val);
        travel(root->right, v);
        return ;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> v;
        travel(root, v);
        return v;
    }
};
