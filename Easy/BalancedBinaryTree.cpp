class Solution {
private:
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int left= height(root->left);
        int right = height(root->right);
        if(abs(left-right)>1 || left == -1 || right == -1) return -1;
        return max(left,right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(height(root) == -1) return false;
        return true;
    }
};
