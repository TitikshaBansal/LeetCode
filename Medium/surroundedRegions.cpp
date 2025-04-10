class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col) {
        int m = board.size(), n = board[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') return;

        board[row][col] = '#'; // mark as visited/safe

        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        // Run DFS for 'O's on the border
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }

        // Final update
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X'; // flip unvisited 'O'
                else if(board[i][j] == '#') board[i][j] = 'O'; // restore safe 'O'
            }
        }
    }
};


// https://leetcode.com/problems/surrounded-regions/
