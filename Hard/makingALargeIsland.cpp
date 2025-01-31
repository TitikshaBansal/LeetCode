class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != 1) return 0;
        
        grid[r][c] = id; 
        int size = 1;
        
        for (auto& d : directions) size += dfs(grid, r + d[0], c + d[1], id);
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        unordered_map<int, int> islandSize;
        int id = 2;
        int maxIsland = 0;
        bool hasZero = false;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1) {
                    int size = dfs(grid, r, c, id);
                    islandSize[id] = size;
                    maxIsland = max(maxIsland, size);
                    id++;
                } 
                else if (grid[r][c] == 0) hasZero = true;
            }
        }

        if (!hasZero) return n * m;

        int bestNewSize = maxIsland;
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 0) {
                    unordered_set<int> uniqueIslands;
                    int newSize = 1; 
                    
                    for (auto& d : directions) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] > 1) {
                            uniqueIslands.insert(grid[nr][nc]);
                        }
                    }

                    for (int island : uniqueIslands) {
                        newSize += islandSize[island];
                    }
                    
                    bestNewSize = max(bestNewSize, newSize);
                }
            }
        }

        return bestNewSize;
    }
};

// https://leetcode.com/problems/making-a-large-island/?envType=daily-question&envId=2025-01-31
