class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        map<int,int> m;
        if(root== nullptr) return {};
        q.push({root,0});
        while(!q.empty()){
            auto temp= q.front();
            TreeNode* node= temp.first;
            int level= temp.second;
            q.pop();

            if(m.find(level)==m.end()) m[level]= node->val;

            if(node->right) q.push({node->right, level+1});
            if(node->left) q.push({node->left, level+1});
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
