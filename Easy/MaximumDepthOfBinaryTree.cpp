class Solution {
    public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int left= height(root->left);
        int right= height(root->right);
        int h= max(left, right)+1;
        return h;

    }
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left= height(root->left);
        int right= height(root->right);
        int h= max(left, right)+1;
        return h;
        
    }
};
