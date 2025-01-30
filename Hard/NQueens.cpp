class Solution {
public:
    vector<vector<string>> solutions; 
    vector<int> col, diag1, diag2; 

    void solve(int n, int row, vector<string>& board) {
        if (row == n) {
            solutions.push_back(board); 
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1]) continue; 

            board[row][c] = 'Q';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;

            solve(n, row + 1, board);

            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        solutions.clear();
        col.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);
        vector<string> board(n, string(n, '.')); 
        
        solve(n, 0, board);
        return solutions;
    }
};

// https://leetcode.com/problems/n-queens/
