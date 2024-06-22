class Solution {
private:
    void travel(TreeNode* root, vector<int> &v){
        if(root== nullptr)return;
        v.push_back(root->val);
        travel(root->left, v);
        travel(root->right, v);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> v;
        travel(root, v);
        return v;
    }
};
