class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y){
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') return;

        grid[x][y] = '0';  // mark visited

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        for (int i = 0; i < 4; ++i){
            dfs(grid, x + dx[i], y + dy[i]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), island = 0;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == '1'){
                    ++island;
                    dfs(grid, i, j);
                }
            }
        }
        return island;
    }
};

// https://leetcode.com/problems/number-of-islands/
