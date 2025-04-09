class Solution {
    int n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    void dfs(int i, int j, vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return;
        
        grid[i][j] = 2;  // Mark as visited (part of first island)
        q.push({i, j});

        for(auto& dir : directions) {
            dfs(i + dir[0], j + dir[1], grid, q);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;

        // Step 1: Find first island and mark it using DFS
        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < n && !found; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid, q);
                    found = true;
                }
            }
        }

        // Step 2: BFS to reach second island
        int flips = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [x, y] = q.front(); q.pop();
                for(auto& dir : directions) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if(grid[nx][ny] == 1) return flips; // Second island found
                        if(grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            flips++;
        }
        return -1; // Should never reach here
    }
};

// https://leetcode.com/problems/shortest-bridge/
