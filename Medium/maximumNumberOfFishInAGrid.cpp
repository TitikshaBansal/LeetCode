class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        auto dfs = [&](int r, int c, auto& dfs) -> int {
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
                return 0;
            }

            int fish = grid[r][c];
            grid[r][c] = 0;

            fish += dfs(r + 1, c, dfs); 
            fish += dfs(r - 1, c, dfs); 
            fish += dfs(r, c + 1, dfs); 
            fish += dfs(r, c - 1, dfs); 

            return fish;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) { 
                    maxFish = max(maxFish, dfs(i, j, dfs));
                }
            }
        }
        return maxFish;
    }
};

// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/?envType=daily-question&envId=2025-01-28
