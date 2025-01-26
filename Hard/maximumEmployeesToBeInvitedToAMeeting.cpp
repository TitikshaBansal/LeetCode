class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0), chainLength(n, 0);
        
        for (int f : favorite) indegree[f]++;
        queue<int> q;
        for (int i = 0; i < n; ++i) if (indegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int fav = favorite[node];
            chainLength[fav] = max(chainLength[fav], chainLength[node] + 1);
            if (--indegree[fav] == 0) {
                q.push(fav);
            }
        }

        vector<bool> visited(n, false);
        int maxCycleSize = 0, mutualPairsSize = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> cycleNodes;
                int current = i;

                while (!visited[current]) {
                    visited[current] = true;
                    cycleNodes.push_back(current);
                    current = favorite[current];
                }

                if (find(cycleNodes.begin(), cycleNodes.end(), current) != cycleNodes.end()) {
                    int cycleStart = find(cycleNodes.begin(), cycleNodes.end(), current) - cycleNodes.begin();
                    int cycleSize = cycleNodes.size() - cycleStart;

                    if (cycleSize == 2) {
                        int a = cycleNodes[cycleStart];
                        int b = cycleNodes[cycleStart + 1];
                        mutualPairsSize += 2 + chainLength[a] + chainLength[b];
                    } else {
                        maxCycleSize = max(maxCycleSize, cycleSize);
                    }
                }
            }
        }
        return max(maxCycleSize, mutualPairsSize);
    }
};

// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/?envType=daily-question&envId=2025-01-26
