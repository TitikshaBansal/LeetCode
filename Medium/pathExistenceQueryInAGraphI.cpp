class DSU{
public:
    vector<int> parent;

    DSU(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py) parent[py] = px;
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

        for(int i =1; i<n; i++){
            if(nums[i]- nums[i-1] <= maxDiff){
                dsu.unite(i,i-1);
            }
        }

        vector<bool> ans;
        for(auto& q : queries){
            int u = q[0], v = q[1];
            ans.push_back(dsu.find(u) == dsu.find(v));
        }
        return ans;
    }
};

// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
