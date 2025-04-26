const int MOD = 1e9 + 7;
class Solution {
public:

    void dfs(int node, long long value, vector<vector<pair<int, int>>>& graph, vector<long long>& conversion){
        conversion[node] = value;

        for(auto& [neighbor, factor] : graph[node]){
            dfs(neighbor, (value*factor)%MOD, graph, conversion);
        }
    }
    
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        vector<vector<pair<int, int>>> graph(n);
        for(auto& conv : conversions){
            int u = conv[0];
            int v = conv[1];
            int factor = conv[2];
            graph[u].push_back({v,factor});
        }

        vector<long long> conversion(n,0);
        dfs(0,1,graph, conversion);

        vector<int> result(n);
        for(int i=0; i<n; i++){
            result[i] = conversion[i]%MOD;
        }

        return result;
    }
};

// https://leetcode.com/problems/unit-conversion-i/
