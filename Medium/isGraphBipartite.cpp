class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);  // -1 means unvisited

        for(int start = 0; start < n; ++start) {
            if(visited[start] == -1) {
                queue<int> q;
                q.push(start);
                visited[start] = 0;  // Assign first color

                while(!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for(int adj : graph[curr]) {
                        if(visited[adj] == -1) {
                            visited[adj] = 1 - visited[curr];  // Assign opposite color
                            q.push(adj);
                        }
                        else if(visited[adj] == visited[curr]) {
                            return false;  // Same color adjacent => Not bipartite
                        }
                    }
                }
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/is-graph-bipartite/
