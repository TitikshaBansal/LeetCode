class Solution {
private:
    TreeNode* lca(TreeNode* root ,int n1 ,int n2 ){
        if(root == nullptr) return NULL;
        if(root->val == n1 || root->val == n2 ) return root;
        TreeNode* left= lca(root->left, n1, n2);
        TreeNode* right= lca(root->right, n1, n2);
        if (left == NULL) return right;
        if (right == NULL) return left;
        return root;
    }
    bool path(TreeNode* root, int startValue, string & s, bool rev =0){
        if(root == nullptr) return 0;
        if(root->val == startValue) return 1;
        s += (rev)? "U" : "L";
        if(path(root->left, startValue, s, rev)) return 1;
        s.pop_back();
        s += (rev)? "U" : "R";
        if(path(root->right, startValue, s, rev)) return 1;
        s.pop_back();
        return 0;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root, startValue, destValue);
        string s1="", s2="";
        path(root, startValue, s1, 1);
        path(root, destValue, s2);
        return s1+s2;
        
    }
};
