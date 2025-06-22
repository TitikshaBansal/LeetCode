class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> up(m, vector<int>(n, 0));
        vector<vector<int>> down(m, vector<int>(n, 0));
        int res = 0;

        // Build up pyramids (downward facing)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0 || j == 0 || j == n - 1)
                        down[i][j] = 1;
                    else
                        down[i][j] = 1 + min({down[i - 1][j - 1], down[i - 1][j], down[i - 1][j + 1]});
                    if (down[i][j] > 1)
                        res += down[i][j] - 1;
                }
            }
        }

        // Build inverted pyramids (upward facing)
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (i == m - 1 || j == 0 || j == n - 1)
                        up[i][j] = 1;
                    else
                        up[i][j] = 1 + min({up[i + 1][j - 1], up[i + 1][j], up[i + 1][j + 1]});
                    if (up[i][j] > 1)
                        res += up[i][j] - 1;
                }
            }
        }

        return res;
    }
};

// https://leetcode.com/problems/count-fertile-pyramids-in-a-land/
