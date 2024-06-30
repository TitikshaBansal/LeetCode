class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
    
        while(!q.empty()){
            int size = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(currentLevel);
        }
        return ans;
    }
};
