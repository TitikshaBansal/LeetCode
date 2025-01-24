#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n); 
        vector<int> outDegree(n, 0);         
        queue<int> q; 
        vector<int> safeNodes; 
        
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
            }
            outDegree[u] = graph[u].size();
            if (outDegree[u] == 0) {
                q.push(u);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node); 
            for (int neighbor : reverseGraph[node]) {
                --outDegree[neighbor];
                if (outDegree[neighbor] == 0) { 
                    q.push(neighbor);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

// https://leetcode.com/problems/find-eventual-safe-states/?envType=daily-question&envId=2025-01-24
