class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long top_sum = 0, bottom_sum = 0;

        for (int j = 0; j < n; ++j) top_sum += grid[0][j];

        long long result = LLONG_MAX;

        for (int j = 0; j < n; ++j) {
            top_sum -= grid[0][j];
            result = min(result, max(top_sum, bottom_sum));
            bottom_sum += grid[1][j];
        }

        return result;
    }
};

// https://leetcode.com/problems/grid-game/?envType=daily-question&envId=2025-01-21
