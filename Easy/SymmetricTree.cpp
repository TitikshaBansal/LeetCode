class Solution {
    private:
        bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr && q!=nullptr) return false;
        if(p!=nullptr && q==nullptr) return false;

        bool left= isSameTree(p->left, q->right);
        bool right= isSameTree(p->right, q->left);
        bool val= p->val == q->val;
        if(left && right && val) return true;
        return false;
        
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};
