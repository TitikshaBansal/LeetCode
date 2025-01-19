class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        // Step 1: Build adjacency matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) dist[i][i] = 0;
        for (auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            dist[u][v] = dist[v][u] = 1; // Distance between directly connected nodes is 1
        }

        // Step 2: Precompute all-pairs shortest paths (Floyd-Warshall)
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 3: Iterate over all subsets
        vector<int> result(n - 1, 0);
        for (int subset = 1; subset < (1 << n); ++subset) {
            vector<int> nodes;
            for (int i = 0; i < n; ++i) {
                if (subset & (1 << i)) nodes.push_back(i);
            }

            // Step 4: Check if the subset forms a connected subtree
            int m = nodes.size();
            if (m < 2) continue; // Diameter requires at least 2 nodes
            
            // Verify connectivity using BFS
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(nodes[0]);
            visited[nodes[0]] = true;
            int visitedCount = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor = 0; neighbor < n; ++neighbor) {
                    if ((subset & (1 << neighbor)) && !visited[neighbor] && dist[node][neighbor] == 1) {
                        visited[neighbor] = true;
                        visitedCount++;
                        q.push(neighbor);
                    }
                }
            }

            if (visitedCount != m) continue; // Not a connected subtree

            // Step 5: Compute the diameter of the subtree
            int diameter = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    diameter = max(diameter, dist[nodes[i]][nodes[j]]);
                }
            }

            // Update the result
            if (diameter > 0) result[diameter - 1]++;
        }

        return result;
    }
};

// https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
