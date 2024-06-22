class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root== nullptr) return ans;

        map<int, map<int, vector<int>>> m;
        queue<pair< TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()){
            auto p= q.front();
            q.pop();
            TreeNode* curr= p.first;
            int h= p.second.first;
            int l = p.second.second;

            m[h][l].push_back(curr->val);

            if(curr->left) q.push({curr->left, {h-1, l+1}});
            if(curr->right) q.push({curr->right, {h+1, l+1}});

        }
        for (auto& i : m) {
            vector<int> col;
            for (auto& j : i.second) {
                sort(j.second.begin(), j.second.end());
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};
