class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.length();
        const int INF = 1e9;
        vector<vector<int>> costMatrix(26, vector<int>(26, INF));
        for (int i = 0; i < 26; ++i) {
            costMatrix[i][i] = 0;
        }
        for (int i = 0; i < original.size(); ++i) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            costMatrix[from][to] = min(costMatrix[from][to], cost[i]);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (costMatrix[i][k] < INF && costMatrix[k][j] < INF) {
                        costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
                    }
                }
            }
        }
        long long totalCost = 0;
        for (int i = 0; i < n; ++i) {
            if (source[i] != target[i]) {
                int from = source[i] - 'a';
                int to = target[i] - 'a';
                if (costMatrix[from][to] == INF) return -1; 
                totalCost += costMatrix[from][to];
            }
        }
        return totalCost;
    }
};
