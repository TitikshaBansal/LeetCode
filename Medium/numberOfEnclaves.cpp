class Solution {
public:
    void dfs(vector<vector<int>>& board, int row, int col, int& totalOnes) {
        int m = board.size(), n = board[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 1) return;

        board[row][col] = -1; // mark as visited/safe
        totalOnes--;
        dfs(board, row - 1, col, totalOnes);
        dfs(board, row + 1, col, totalOnes);
        dfs(board, row, col - 1, totalOnes);
        dfs(board, row, col + 1, totalOnes);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int totalOnes = 0;
        for (const auto& row : grid) {
            totalOnes += accumulate(row.begin(), row.end(), 0);
        }

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) dfs(grid, i, 0, totalOnes);
            if(grid[i][n - 1] == 1) dfs(grid, i, n - 1, totalOnes);
        }
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1) dfs(grid, 0, j, totalOnes);
            if(grid[m - 1][j] == 1) dfs(grid, m - 1, j, totalOnes);
        }

        return totalOnes;
    }
};

// https://leetcode.com/problems/number-of-enclaves/
