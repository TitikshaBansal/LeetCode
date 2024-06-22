class Solution {
private:
    void travel(TreeNode* root, vector<int> &v){
        if(root==nullptr) return;
        travel(root->left, v);
        travel(root->right, v);
        v.push_back(root->val);
        return;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> v;
        travel(root, v);
        return v;
        
    }
};
