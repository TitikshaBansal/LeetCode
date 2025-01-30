class Solution {
public:
    int result=0;
    vector<int> col, diag1, diag2;

    void solve(int n, int row, vector<int>& positions) {
        if (row == n) {
            result++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1]) continue;

            positions[row] = c + 1;
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;

            solve(n, row + 1, positions);

            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
        }
    }
    int totalNQueens(int n) {
        col.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);
        vector<int> positions(n, 0);

        solve(n, 0, positions);
        return result;
    }
};

// https://leetcode.com/problems/n-queens-ii/
