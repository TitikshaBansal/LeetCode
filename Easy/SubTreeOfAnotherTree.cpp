class Solution {
private:
    void preOrder(TreeNode* root, vector<int>& v){
        if (root == nullptr) {
            v.push_back(INT_MIN);
            return;
        }
        v.push_back(root->val);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> v1;
        vector<int> v2;
        preOrder(root, v1);
        preOrder(subRoot, v2);
        for(int i=0; i< v1.size(); i++){
            if(v1[i]== subRoot->val){
                vector<int> temp;
                temp.assign(v1.begin()+i, v1.begin()+i+v2.size());
                if(temp == v2) return true;
            }
        }
        return false;
    }
};
