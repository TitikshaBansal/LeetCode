class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); 
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false; 
        
        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        
        for (int i = 0; i <= n; ++i) parent[i] = i; 
        
        for (const auto& edge : edges) {
            if (!unite(edge[0], edge[1])) {
                return edge; 
            }
        }
        
        return {};
    }
};

// https://leetcode.com/problems/redundant-connection/?envType=daily-question&envId=2025-01-29
